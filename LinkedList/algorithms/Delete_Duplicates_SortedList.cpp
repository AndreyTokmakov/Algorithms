/**============================================================================
Name        : Delete_Duplicates_SortedList.cpp
Created on  : 14.01.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../LinkedListAlgorithms.h"

namespace
{
    using namespace LinkedListAlgorithms;

    template<typename T>
    void remove_duplicates_sorted(Node<T>* node)
    {
        Node<T>* previous = nullptr;
        while (nullptr != node) {
            if (node->next && node->data == node->next->data)
                previous->next = node->next;
            else
                previous = node;
            node = previous->next;
        }
    }
}

void LinkedListAlgorithms::Delete_Duplicates_SortedList()
{
    Node<int>* list = InitList({ 1,2,3,3,4,5,6,6,6,6,7,8 });
    PrintList(list, "  -->  ");
    remove_duplicates_sorted(list);
    PrintList(list);
}