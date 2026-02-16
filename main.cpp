#include <iostream>
#include <thread>
#include <vector>

#include "BlockingQueue.h"
#include "Consumer.h"
#include "Producer.h"
#include "Image.h"

int main()
{
    const int WIDTH = 800;
    const int HEIGHT = 600;
    int consumerCount = std::thread::hardware_concurrency();
    int blockSize = 10;

    std::cout << "Consumers: " << consumerCount << std::endl;
    Image image(WIDTH, HEIGHT);
    image.generateTestImage();
    image.save("original.ppm");
    BlockingQueue<Task> queue;
    Producer producer(queue, image, blockSize, consumerCount);

    std::thread producerThread(&Producer::run, &producer);
    std::vector<std::thread> consumers;
    std::vector<std::unique_ptr<Consumer>> consumerObjects;
    for(int i = 0; i < consumerCount; i++)
    {
        consumerObjects.push_back(std::make_unique<Consumer>(queue, image, i));
        consumers.emplace_back(&Consumer::run, consumerObjects.back().get());
    }
    producerThread.join();
    for(auto& t : consumers)
    {
        t.join();
    }
    image.save("result.ppm");
    std::cout << "Finished" << std::endl;
    return 0;
}
