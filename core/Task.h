#pragma once

class Task
{
public:
    int startRow;
    int endRow;
    bool stop;

    Task(int s=0,int e=0,bool st=false) : startRow(s), endRow(e), stop(st) {}

    static Task Stop()
    {
        return Task(0,0,true);
    }
};