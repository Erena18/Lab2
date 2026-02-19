#include "../core/Image.h"
#include "../core/Producer.h"
#include "../core/Consumer.h"
#include "../core/BlockingQueue.h"

#include <filesystem>
#include <vector>
#include <random>
#include <thread>
#include <iostream>

void runRandomImageTest()
{
    std::vector<std::string> files;
    for(auto& entry:std::filesystem::directory_iterator("images"))
    {
        files.push_back(entry.path().string());
    }
    if(files.empty())
    {
        std::cout<<"No images in folder\n";
        return;
    }
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0,files.size()-1);
    std::string randomFile = files[dis(gen)];
    Image img;
    if(!img.load(randomFile))
    {
        std::cout<<"Failed to load image\n";
        return;
    }

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
    img.save("random_result.png");
}
