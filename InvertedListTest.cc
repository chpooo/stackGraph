#include "InvertedList.h"
#include <cstdint>
#include "cstdio"
using namespace dima;

int main()
{
    InvertedList * tmp = new InvertedList((uint64_t)10);
    uint64_t key1 = 0;
    uint64_t key2 = 2;
    tmp->insert(key1,(uint64_t)0);
    tmp->insert(key1,(uint64_t)3);
    tmp->insert(key1,(uint64_t)7);
    tmp->insert(key2,(uint64_t)0);
    tmp->insert(key2,(uint64_t)7);
    uint64_t count;
    tmp->unionTwoSet(count,key1,key2);
    printf("%d\n",count);
}
