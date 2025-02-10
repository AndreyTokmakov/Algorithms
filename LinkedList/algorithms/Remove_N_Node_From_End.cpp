/**============================================================================
Name        : Remove_N_Node_From_End.cpp
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
    Node<T>* _remove_N_Node_From_End(Node<T>* root, int N)
    {
        Node<T>* node = root, *tmp = root;
        while (node && N-- >= 0)
            node = node->next;
        while (node) {
            node = node->next;
            tmp = tmp->next;
        }

        tmp->next = tmp->next->next;
        return root;
    }
}

void LinkedListAlgorithms::Remove_N_Node_From_End()
{
    Node<int>* root = InitList({ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 });
    constexpr int N = 7;
    _remove_N_Node_From_End(root, N);

    PrintList(root);
}