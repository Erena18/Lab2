#include "../core/Image.h"
#include "../core/Producer.h"
#include "../core/Consumer.h"
#include "../core/BlockingQueue.h"
#include <vector>
#include <thread>
#include <iostream>

void runGeneratedTest()
{
    Image img;
    img.generateTestImage(800,600);
    BlockingQueue<Task> queue;
    int threads = std::thread::hardware_concurrency();
    Producer producer(queue,img,10,threads);
    std::thread prod(&Producer::run,&producer);
    std::vector<std::thread> consumers;
    for(int i=0;i<threads;i++)
    {
        consumers.emplace_back([&]
        {
          Consumer c(queue, img, i);  
          c.run();
        });
    }
    prod.join();
    for(auto& t:consumers) t.join();
    img.save("generated_result.png");
}
