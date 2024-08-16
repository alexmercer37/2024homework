#include "../inc/queue.hpp"
int main(int argc, char const *argv[])
{
    Queue q;

    int a = 10;
    q.push(&a);
    std::cout << *(int *)q.getfront() << std::endl; // 输出 10
    q.pop();
    if (q.empty())
    {
        std::cout << "Queue is empty." << std::endl;
    }
    return 0;
}
