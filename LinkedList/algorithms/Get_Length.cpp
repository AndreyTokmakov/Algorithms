/**============================================================================
Name        : Get_Length.cpp
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
    size_t get_length(Node<T>* root)
    {
        size_t len = 0;
        while (nullptr != root) {
            root = root->next;
            len++;
        }
        return len; // Return root
    }

    template<typename T>
    size_t get_length_2(const Node<T>* root)
    {
        return nullptr == root ? 0 : 1 + get_length_2(root->next);
    }
}

void LinkedListAlgorithms::Get_Length()
{
    Node<int>* root = InitList({ 1,2,3,4,5,6,7,8,9 });
    PrintList(root);
    std::cout << "Length: " << get_length(root) << std::endl;
    std::cout << "Length: " << get_length_2(root) << std::endl;
}