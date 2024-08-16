#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <stdlib.h>
class LinkNode
{
public:
    void *data;
    LinkNode *pred;
    LinkNode *succ;
    LinkNode()
    {
        data = nullptr;
        pred = nullptr;
        succ = nullptr;
    }
};

class LinkList : public LinkNode
{
private:
    LinkNode *header;
    LinkNode *trailer;
    int size;

public:
    LinkList()
    {
        header = new LinkNode();
        trailer = new LinkNode();
        header->succ = trailer;
        //! 头节点的后继是尾节点
        trailer->pred = header;
        //! 尾节点的前驱是头节点
        size = 0;
        //! 长度为0
    };
    ~LinkList()
    {
        LinkNode *current = header->succ;
        //! 头节点的后继
        while (current != trailer)
        {
            LinkNode *temp = current;
            current = current->succ;
            delete temp;
        }
        delete header;
        delete trailer;
    }
    void Insert_List(int pos, void *Data)
    {
        if (pos < 0 || pos > size)
        {
            pos = size;
        }
        LinkNode *newnode = new LinkNode;
        //! 创建一个新的节点
        newnode->data = Data;
        //! 传入的数据
        newnode->succ = header->succ;
        //! 新节点的后继是头节点的后继
        newnode->pred = header;
        //! 新节点的前驱是头节点
        header->succ->pred = newnode;
        //! 头节点后继的前驱指向新节点
        header->succ = newnode;
        //! 头节点的后继为新节点
        size++;
    }
    void Delete_List(int pos)
    {
        if (data == nullptr)
        {
            return;
        }
        if (pos < 0 || pos >= size)
        {
            pos = size;
        }

        LinkNode *pDel = header->succ;
        for (int i = 0; i < pos; i++)
        {
            pDel->succ = pDel;
        }
        pDel->pred->succ = pDel->succ;
        pDel->succ->pred = pDel->pred;
        delete pDel;
        size--;
    }
    void *Find_List(void *Data)
    {
        if (data == nullptr)
        {
            return nullptr;
        }
        if (data == nullptr)
        {
            return nullptr;
        }
        LinkNode *pCurrent = header->succ;

        while (pCurrent != trailer)
        {
            if (pCurrent->data == Data)
            {
                return data;
            }

            pCurrent->succ = pCurrent;
        }
        return nullptr;
    }
    void Print_List()
    {
        LinkNode *pCurrent = header->succ;
        while (pCurrent != trailer)
        {
            std::cout << pCurrent->data << std::endl;
            pCurrent = pCurrent->succ;
        }
    }
    void Copy_Nodes()
    {
        LinkList list;
        for (int i = 0; i < size; i++)
        {
            LinkNode *pCurrent = header->succ;
            for (int j = 0; j < i; j++)
            {
                pCurrent = pCurrent->succ;
            }
            list.Insert_List(i, pCurrent->data);
        }
    }
    void Delete_Same_List(int pos)
    {
        if (data == nullptr)
        {
            return;
        }
        if (pos < 0 || pos >= size)
        {
            pos = size;
        }

        LinkNode *pCUrrent = header;
        for (int i = 0; i < size; i++)
        {
            pCUrrent->succ = pCUrrent;
        }
        void *q = pCUrrent->data;
        void *p = Find_List(q);
        if (p == q)
        {
            Delete_List(pos);
            size--;
        }
    }
};
#endif