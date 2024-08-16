#include "../inc/stack.hpp"
typedef u_int64_t DDD;
int main(int argc, char const *argv[])
{
    Stack s;
    int a = 10;
    s.push(&a);
    cout << *(int *)s.gettop() << endl; // 输出 10
    s.pop();
    if (s.empty())
    {
        cout << "Stack is empty." << endl;
    }
    return 0;
}
