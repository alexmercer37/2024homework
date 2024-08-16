#include "../inc/list.hpp"
int main(int argc, char const *argv[])
{
    LinkList list;
    list.Insert_List(0, (void *)1);
    list.Insert_List(1, (void *)2);
    list.Insert_List(2, (void *)3);

    list.Print_List();

    list.Delete_List(1);
    std::cout << "After deleting index 1:\n";
    list.Print_List();

    if (list.Find_List((void *)2))
    {
        std::cout << "2 found\n";
    }
    else
    {
        std::cout << "2 not found\n";
    }
    return 0;
}
