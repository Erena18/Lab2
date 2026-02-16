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
    int height = image.getHeight();

    for(int y = 0; y < height; y += blockSize)
    {
        int end = std::min(y + blockSize, height);

        queue.push(Task(y, end));
    }

    // stop signals
    for(int i = 0; i < consumerCount; i++)
    {
        queue.push(Task::StopTask());
    }
}