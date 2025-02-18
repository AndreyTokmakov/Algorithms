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
    using TestData = std::vector< std::pair<std::vector<int>, std::vector<int>> >;
    for (const auto& [values, expected]:  TestData{
        { {1,2,3,3,4,5,6,6,6,6,7,8}, {1,2,3,4,5,6,7,8} }
    })
    {
        Node<int>* list = InitList(values);
        remove_duplicates_sorted(list);
        const std::vector<int> actual = List2Vector(list);
        if (expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
    }
    std::cout << "OK: All tests passed\n";
}