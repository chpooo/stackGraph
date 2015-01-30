#ifndef INVERTEDLIST_H
#define INVERTEDLIST_H
#include "Common.h"
#include <cstdint>
#include <cstddef>
namespace dima{
class InvertedItem
{
public:
    InvertedItem()
    {
        this->next = NULL;
    }
    InvertedItem(uint64_t data):data(data)
    {
        this->next = NULL;
    }
    uint64_t data;
    InvertedItem * next;
};
class InvertedHeadItem{
public:
    InvertedHeadItem()
    {
        this->head=NULL;
        this->end = NULL;
    }
    InvertedItem * head;
    InvertedItem * end;
};
class InvertedList{
public:
    InvertedList(uint64_t bucketNum)
    :bucketNum(bucketNum)
    {
        this->data = new InvertedHeadItem *[bucketNum];
        for(int i = 0;i<bucketNum;i++)
        {
            this->data[i] = new InvertedHeadItem();
        }
    }
    ~InvertedList()
    {
        delete this->data;
    }
    stackg::STATUS insert(uint64_t key,uint64_t data);
    stackg::STATUS unionTwoSet(uint64_t &count,uint64_t key1, uint64_t key2);
private:
    uint64_t bucketNum;
    InvertedHeadItem ** data;
};
}
#endif // INVERTEDLIST_H
