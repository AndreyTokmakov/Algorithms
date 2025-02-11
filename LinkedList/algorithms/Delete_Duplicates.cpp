/**============================================================================
Name        : Delete_Duplicates.cpp
Created on  : 14.01.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../LinkedListAlgorithms.h"

#include <unordered_set>

namespace
{
    using namespace LinkedListAlgorithms;

    template<typename T>
    Node<int>* delete_duplices(Node<T>* root)
    {
        Node<T>* prev = root, * next = nullptr != root ? root->next : nullptr;
        std::unordered_set<T> tmp = { root->data };

        while (nullptr != next) {
            if (true == tmp.insert(next->data).second) {
                prev->next = next;
                prev = prev->next;
            }
            next = next->next;
        }
        return root;
    }

    template<typename T>
    void remove_duplicates(Node<T>* node)
    {
        Node<T>* previous = nullptr;
        std::unordered_set<T> tmp;

        while (nullptr != node) {
            if (false == tmp.insert(node->data).second)
                previous->next = node->next;
            else
                previous = node;
            node = previous->next;
        }
    }

    template<typename T>
    void remove_duplicates_2(Node<T>* node)
    {
        Node<T>* previous = nullptr;
        std::unordered_set<T> tmp;

        while (nullptr != node) {
            if (false == tmp.insert(node->data).second) {
                previous->next = node->next;
                node = previous->next;
            }
            previous = node;
            if (nullptr == node)
                return;
            node = node->next;
        }
    }
}

void LinkedListAlgorithms::Delete_Duplicates()
{
    std::cout << "--------------------- Test1: ------------------\n" << std::endl;
    {
        Node<int>* list = InitList({ 1,2,3,3,4,5,6,6,7,8 });
        PrintList(list, "  -->  ");
        PrintList(delete_duplices(list), "\n\n");
    }
    std::cout << "\n--------------------- Test2: ------------------\n" << std::endl;
    {
        Node<int>* list = InitList({ 1,2,3,3,4,5,6,6,7,8 });
        PrintList(list, "  -->  ");
        remove_duplicates(list);
        PrintList(list);
    }
    std::cout << "\n--------------------- Test3: ------------------\n" << std::endl;
    {
        Node<int>* list = InitList({ 1,2,3,3,4,5,6,6,7,8 });
        PrintList(list, "  -->  ");
        remove_duplicates_2(list);
        PrintList(list);
    }
}