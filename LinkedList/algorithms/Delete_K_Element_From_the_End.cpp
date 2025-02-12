/**============================================================================
Name        : Delete_K_Element_From_the_End.cpp
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
    Node<int>* _delete_K_node_from_the_end(Node<T>* root, int K)
    {
        Node<T>* currentNode = root, *nodeToSkip { nullptr };
        while (nullptr != currentNode) {
            if (K-- == 0)
                nodeToSkip = root;
            else if (K < 0) {
                nodeToSkip = nodeToSkip->next;
            }
            currentNode = currentNode->next;
        }
        if (nodeToSkip->next->next) {
            nodeToSkip->next = nodeToSkip->next->next;
        }
        return root;
    }

}

void LinkedListAlgorithms::Delete_K_Element_From_the_End()
{
    Node<int>* list = InitList({ 1,2,3,4,5,6,7,8,9 });
    PrintList(list, "  -->  ");
    list = _delete_K_node_from_the_end(list, 2);
    PrintList(list);
}