#pragma once
#include <queue>
#include <mutex>
#include <condition_variable>

template<typename T>

class BlockingQueue
{
public:
    void push(const T& item) //добавление задачи в очередь
    {
        std::unique_lock<std::mutex> lock(mutex);
        queue.push(item);
        c_v.notify_one();
    }
    T pop() //удаление задачи из очереди
    {
        std::unique_lock<std::mutex> lock(mutex);
        c_v.wait(lock, [this]()
        {
            return !queue.empty();
        });
        T item = queue.front();
        queue.pop();
        return item;
    }
private:
    std::queue<T> queue; //для хранения задач
    std::mutex mutex; //защита от одновременного доступа к очереди
    std::condition_variable c_v; //уведомление потоков , что в очереди появились задачи
};