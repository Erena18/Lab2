#pragma once

class Task
{
public:

    int startRow;
    int endRow;
    bool stop;

    Task()
        : startRow(0), endRow(0), stop(false)
    {}

    Task(int start, int end)
        : startRow(start), endRow(end), stop(false)
    {}

    static Task StopTask()
    {
        Task t;
        t.stop = true;
        return t;
    }
};