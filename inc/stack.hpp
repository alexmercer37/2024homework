#ifndef STACK_H
#define STACK_H

#include <iostream>
#define MAXSIZE 100
using namespace std;

class Stack
{
private:
    void **stack;
    // int *stack;
    // std::vector<int> stack;
    //! 利用c++标准库容器进行自动内存分配
    int size;

public:
    Stack()
    {
        *stack = new void *[MAXSIZE];
        size = -1;
    }
    ~Stack()
    {
        delete[] stack;
    }
    bool empty()
    {
        return size == -1;
    }
    void push(void *data)
    {
        if (size == MAXSIZE - 1)
            return;
        size++;
        stack[size] = data;
    }
    void pop()
    {
        if (empty())
            return;
        stack[size] = nullptr;
        size--;
    }
    void *gettop()
    {
        if (empty())
            return nullptr;
        void *data = stack[size];
        return data;
    }
};
#endif
