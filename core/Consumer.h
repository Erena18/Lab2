#pragma once
#include "BlockingQueue.h"
#include "Task.h"
#include "Image.h"

class Consumer
{
public:
    Consumer(BlockingQueue<Task>& queue, Image& image,int id);
    void run();

private:
    BlockingQueue<Task>& queue; //ссылка на общую очередь
    Image& image; //ссылка на общ. изобр.
    int id; //id потока
};
