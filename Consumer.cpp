#include "Consumer.h"
#include <iostream>

Consumer::Consumer(BlockingQueue<Task>& queue, Image& image, int id): 
queue(queue), image(image), id(id) {}

void Consumer::run()
{
    while(true)
    {
        Task task = queue.pop();
        if(task.stop)
        {
            std::cout << "Consumer "<< id << " stopped" << std::endl;
            break;
        }
        image.invertBlock(task.startRow, task.endRow); //инверсия цвета
    }
}
