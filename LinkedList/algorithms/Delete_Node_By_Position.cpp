/**============================================================================
Name        : Delete_Node_By_Position.cpp
Created on  : 10.02.2025
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
    Node<int>* _delete_node_by_pos(Node<T>* root, size_t pos)
    {
        // TODO: return root->next IF pos == 0
        Node<T>* node = root;
        while (nullptr != node && node->next != nullptr) {
            pos--;
            if (0 == pos) {
                node->next = node->next->next;
                return root;
            }
            node = node->next;
        }
        return root;
    }

    template<typename T>
    Node<int>* _delete_node_by_pos_2(Node<T>* root, size_t pos)
    {
        // TODO: return root->next IF pos == 0
        Node<T>* previous = root, *current = root ? root->next : nullptr;
        while (nullptr != current) {
            pos--;
            if (0 == pos) {
                previous->next = current->next;
                return root;
            }
            previous = current;
            current = previous->next;
        }
        return root;
    }

    template<typename T>
    Node<int>* _delete_node_by_pos_3(Node<T>* root, size_t pos)
    {
        if (0 == pos)
            return root->next;

        Node<T>* previous = root;
        while (nullptr != root) {
            if (pos--)
                previous = root;
            else {
                previous->next = root->next;
                break;
            }
            root = previous->next;
        }
    }


}

void LinkedListAlgorithms::Delete_Node_By_Position()
{
    {
        Node<int>* list = InitList({ 1,2,3,4,5,6,7,8,9 });
        PrintList(list, "  -->  ");
        list = _delete_node_by_pos(list, 1);
        PrintList(list);
    }
    {
        Node<int>* list = InitList({ 1,2,3,4,5,6,7,8,9 });
        PrintList(list, "  -->  ");
        list = _delete_node_by_pos(list, 8);
        PrintList(list);
    }
    {
        Node<int>* list = InitList({ 1,2,3,4,5,6,7,8,9 });
        PrintList(list, "  -->  ");
        list = _delete_node_by_pos_2(list, 1);
        PrintList(list);
    }
    {
        Node<int>* list = InitList({ 1,2,3,4,5,6,7,8,9 });
        list = nullptr;
        PrintList(list, "  -->  ");
        _delete_node_by_pos_3(list, 1);
        PrintList(list);
    }
}