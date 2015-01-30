#include "InvertedList.h"
#include "Common.h"
#include <cstdint>
#include <cstddef>
namespace dima{
    stackg::STATUS InvertedList::insert(uint64_t key,uint64_t data){
        InvertedHeadItem * tmp = this->data[key];
        InvertedItem * newItem = new InvertedItem(data);
        if(tmp->head==NULL){
            tmp->head = newItem;
            tmp->end = newItem;
        }
        else{
            tmp->end->next = newItem;
            tmp->end = newItem;
        }
        return stackg::SUCCESS;
    }
    stackg::STATUS InvertedList::unionTwoSet(uint64_t &count, uint64_t key1, uint64_t key2){
        count = 0;
        InvertedHeadItem * tmp1 = this->data[key1];
        InvertedHeadItem * tmp2 = this->data[key2];
        InvertedItem * iterator1 = tmp1->head;
        InvertedItem * iterator2 = tmp2->head;
        while(true)
        {
            if(iterator1==NULL||iterator2==NULL){
                break;
            }
            if(iterator1->data == iterator2->data)
            {
                count++;
                iterator1 = iterator1->next;
                iterator2 = iterator2->next;
            }
            else
            {
                if(iterator1->data > iterator2->data){
                    iterator2 = iterator2->next;
                }else{
                    iterator1 = iterator1->next;
                }
            }
        }
        return  stackg::SUCCESS;
    }
}
