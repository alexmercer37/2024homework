#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <vector>
#define MAXSIZE 100
using namespace std;
class Queue
{
private:
    void **queue;
    // std::vector<int> queue;
    //! 利用c++标准库容器进行自动内存分配
    int front, rear;

public:
    Queue()
    {
        queue = new void *[MAXSIZE];
        front = rear = -1;
    }

    ~Queue()
    {
        delete[] queue;
    }
    bool empty()
    {
        return (front == rear);
    }
    bool isfull()
    {
        if ((rear + 1) % (MAXSIZE) == front)
            return 1;

        return (front == rear);
    }
    void push(void *data)
    {
        if (rear == MAXSIZE - 1)
            return;
        rear = (rear + 1) % MAXSIZE;
        queue[rear] = data;
    }
    void pop()
    {
        if (empty())
            return;
        if (front == rear)
            return;
        front = (front + 1) % MAXSIZE;
        queue[front] = nullptr;
    }
    void *getfront()
    {
        if (front == rear)
            return nullptr;
        int head = front + 1;
        void *data = queue[head];
        return data;
    }
    void *getdata(int num)
    {
        return queue[(front + num) % MAXSIZE];
    }
};
#endif
