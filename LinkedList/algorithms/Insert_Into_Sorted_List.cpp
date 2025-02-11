/**============================================================================
Name        : Insert_Into_Sorted_List.cpp
Created on  : 11.02.2025
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
    Node<int>* insert_into_sorted_list(Node<T>* root, T value)
    {
        Node<T>* node = root, *previous = nullptr, *newNode = new Node<T>(value);
        if (nullptr == root || root->data > value) {
            newNode->next = root;
            return newNode;
        }

        while (nullptr != node)
        {
            if (node->data > value) {
                newNode->next = node;
                previous->next = newNode;
                return root;
            }
            previous = node;
            node = node->next;
        }

        previous->next = newNode;
        return root;
    }

    template<typename T>
    Node<int>* _insert_into_sorted_list_3(Node<T>* root, T value)
    {
        Node<T>* const new_node = new Node<T>(value);
        if (nullptr == root || root->data > value) {
            new_node->next = root;
            return new_node;
        }

        Node<T> *node = root->next, *prev = root;
        while (nullptr != node && node->data <= value) {
            prev = node;
            node = node->next;
        }

        prev->next = new_node;
        new_node->next = node;

        return root;
    }
}

void LinkedListAlgorithms::Insert_Into_Sorted_List()
{
    for (Node<int>* list: {
        InitList({ 1,2,4,6,8}), InitList({ 3}), InitList({ 23}),
        InitList({ 1,2,4,6,8,10}), InitList({ 1,5,10,15,20}), InitList({ 1,2,4,6,8,10,12,14 }),
        static_cast<Node<int>*>(nullptr)
    })
    {
        PrintList(list, " => ");
        const Node<int>* result = insert_into_sorted_list(list, 9);
        PrintList(result);
    }

    std::cout << std::string(180, '-') << std::endl;

    for (Node<int>* list: {
        InitList({ 1,2,4,6,8}), InitList({ 3}), InitList({ 23}),
        InitList({ 1,2,4,6,8,10}), InitList({ 1,5,10,15,20}), InitList({ 1,2,4,6,8,10,12,14 }),
        static_cast<Node<int>*>(nullptr)
    })
    {
        PrintList(list, " => ");
        const Node<int>* result = _insert_into_sorted_list_3(list, 9);
        PrintList(result);
    }
}