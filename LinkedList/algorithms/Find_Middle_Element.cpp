/**============================================================================
Name        : Find_Middle_Element.cpp
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

    void findMiddle(const Node<int>* root)
    {
        size_t steps = 0;
        const Node<int>* mid = root;
        while (nullptr != root) {
            root = root->next;
            if (0 == (steps++) % 2)
                mid = mid->next;
        }
        std::cout << mid->data << std::endl;
    }

    void findMiddle2(const Node<int>* root)
    {
        const Node<int>* slow = root, *fast = root;
        while (nullptr != fast && nullptr != fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        std::cout << slow->data << std::endl;
    }

}

void LinkedListAlgorithms::Find_Middle_Element()
{
    Node<int>* root = InitList({ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 });

    findMiddle(root);
    findMiddle2(root);
}