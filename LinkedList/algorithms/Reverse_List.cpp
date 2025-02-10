/**============================================================================
Name        : Reverse_List.cpp
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
    Node<T>* reverse_list(Node<T>* root)
    {
        Node<int>* prev = nullptr, * current = root, * next = nullptr;
        while (nullptr != current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev; // Return root
    }

    template<typename T>
    Node<T>* reverse_list_2(Node<T>* node)
    {
        Node<int>* previous{ nullptr }, * next{ nullptr };
        while (nullptr != node) {
            next = node->next;
            node->next = previous;
            previous = node;
            node = next;
        }
        return previous; // Return root
    }

}

void LinkedListAlgorithms::Reverse_List()
{
    {
        Node<int>* root = InitList({ 1,2,3,4,5,6,7,8,9 });

        PrintList(root);
        root = reverse_list(root);
        PrintList(root);
    }
    {
        Node<int>* root = InitList({ 1,2,3,4,5,6,7,8,9 });

        PrintList(root);
        root = reverse_list_2(root);
        PrintList(root);
    }
}