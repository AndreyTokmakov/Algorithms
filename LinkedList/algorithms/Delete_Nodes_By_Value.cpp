/**============================================================================
Name        : Delete_Nodes_By_Value.cpp
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
    Node<int>* delete_nodes(Node<T>* root, const T value)
    {
        while (nullptr != root && value == root->data)
            root = root->next;

        Node<T>* prev = root;
        Node<T>* next = nullptr != root ? root->next : nullptr;
        while (nullptr != next) {
            if (value != next->data) {
                prev->next = next;
                prev = prev->next;
            }
            next = next->next;
        }
        return root;
    }

    template<typename T>
    Node<int>* delete_nodes_2(Node<T>* root, const T value)
    {
        while (nullptr != root && value == root->data)
            root = root->next;

        Node<T>* previous = root, * current = root ? root->next : nullptr;
        while (nullptr != current)
        {
            if (value == current->data)
                previous->next = current->next;
            else
                previous = current;
            current = previous->next;
        }
        return root;
    }

    template<typename T>
    Node<int>* delete_nodes_3(Node<T>* root, const T value)
    {
        Node<T>* previous = root, * current = root ? root->next : nullptr;
        while (nullptr != current) {
            if (value == current->data)
                previous->next = current->next;
            else
                previous = current;
            current = previous->next;
        }
        return root && root->data == value ? root->next : root;
    }
}

void LinkedListAlgorithms::Delete_Nodes_By_Value()
{
    for (const std::vector<int>& data: std::vector<std::vector<int>> {
            { 5,1,5,5,2,4,5,5,5,7,8,9 }, { 5,1,5,5,2,4,5,5,5,7,8,9 }, { 5,5,5 },
        {} // FIXME: Bug with empty
    })
    {
        {
            Node<int>* list = InitList(data);
            PrintList(list, "  -->  ");
            PrintList(delete_nodes(list, 5));
        }
        {
            Node<int>* list = InitList(data);
            PrintList(list, "  -->  ");
            PrintList(delete_nodes_2(list, 5));
        }
        {
            Node<int>* list = InitList(data);
            PrintList(list, "  -->  ");
            PrintList(delete_nodes_3(list, 5));
        }
        std::cout << std::string(180, '-') << std::endl;
    }
}