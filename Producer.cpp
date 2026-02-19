#include "Producer.h"

Producer::Producer(
    BlockingQueue<Task>& queue,
    Image& image,
    int blockSize,
    int consumerCount
)
    : queue(queue),
      image(image),
      blockSize(blockSize),
      consumerCount(consumerCount)
{}

void Producer::run()
{
    for(int y=0;y<image.height();y+=blockSize)
    {
        int end = std::min(y+blockSize,image.height());
        queue.push(Task(y,end,false));
    }

    for(int i=0;i<consumerCount;i++)
        queue.push(Task::Stop());
}
