#pragma once
#include "BlockingQueue.h"
#include "Task.h"
#include "Image.h"
class Producer
{
public:
    Producer(BlockingQueue<Task>& queue, Image& image, int blockSize, int consumerCount);

    void run();
private:
    BlockingQueue<Task>& queue;
    Image& image;
    int blockSize;
    int consumerCount;
};
