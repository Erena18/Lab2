#include "Consumer.h"
#include <iostream>

Consumer::Consumer(BlockingQueue<Task>& queue, Image& image, int id): 
queue(queue), image(image), id(id) {}

void Consumer::run()
{
    while(true)
    {
        Task t = queue.pop();
        if(t.stop) break;

        image.invertBlock(t.startRow,t.endRow);
    }
}
