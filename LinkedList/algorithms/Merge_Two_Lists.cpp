/**============================================================================
Name        : Merge_Two_Lists.cpp
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
    Node<int>* merge_recursion(Node<T>* node1, Node<T>* node2)
    {
        if (nullptr == node1)
            return node2;
        else if (nullptr == node2)
            return node1;

        if (node1->data < node2->data) {
            node1->next = merge_recursion(node1->next, node2);
            return node1;
        }
        else {
            node2->next = merge_recursion(node1, node2->next);
            return node2;
        }
    }

    void Merge_Two_Lists_Recur()
    {
        Node<int>* list1 = InitList({ 0,2,4,6,8,10,12,14 });
        Node<int>* list2 = InitList({ 1,3,5,7,9,11,13,15 });

        PrintList(list1);
        PrintList(list2);
        Node<int>* result = merge_recursion(list1, list2);
        PrintList(result);
    }
}

namespace
{
    Node<int>* merge(Node<int>* node1, Node<int>* node2);

    Node<int>* merge2(Node<int>* node1, Node<int>* node2)
    {
        node1->next = merge(node1->next, node2);
        return node1;
    }

    Node<int>* merge(Node<int>* node1, Node<int>* node2)
    {
        if (nullptr == node1)
            return node2;
        else if (nullptr == node2)
            return node1;
        return node1->data < node2->data ? merge2(node1, node2) : merge2(node2, node1);
    }

    void Merge_Two_Lists_2()
    {
        Node<int>* list1 = InitList({ 0,2,4,6,8,10,12,14 });
        Node<int>* list2 = InitList({ 1,3,5,7,9,11,13,15 });

        PrintList(list1);
        PrintList(list2);
        Node<int>* result = merge(list1, list2);
        PrintList(result);
    }
}

namespace
{
    template<typename T>
    Node<int>* merge_recursion_non_recur(Node<T>* node1,
                                         Node<T>* node2)
    {
        Node<int>* root = nullptr;
        if (node1->data < node2->data) {
            root = node1;
            node1 = node1->next;
        } else {
            root = node2;
            node2 = node2->next;
        }

        Node<int>* node = root;
        while (node1 && node2)
        {
            if (node1->data < node2->data) {
                node->next = node1;
                node1 = node1->next;
            }
            else {
                node->next = node2;
                node2 = node2->next;
            }
            node = node->next;
        }

        return root;
    }

    void Merge_Two_Lists_NonRecursive()
    {
        Node<int>* list1 = InitList({ 0,2,4,6,8,10,12,14 });
        Node<int>* list2 = InitList({ 1,3,5,7,9,11,13,15 });

        const Node<int>* result = merge_recursion_non_recur(list1, list2);
        PrintList(result);
    }
}

void LinkedListAlgorithms::Merge_Two_Lists()
{
    // Merge_Two_Lists_Recur();
    Merge_Two_Lists_2();
    Merge_Two_Lists_NonRecursive();
}