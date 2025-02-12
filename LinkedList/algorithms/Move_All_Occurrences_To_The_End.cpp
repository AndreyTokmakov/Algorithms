/**============================================================================
Name        : Move_All_Occurrences_To_The_End.cpp
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
    Node<int>* __move_all_occurrences_to_th_end(Node<T>* root, T value) {
        assert(nullptr != root);
        Node<int>* start = nullptr, * tmp1 = nullptr;
        Node<int>* tail = nullptr, * tmp2 = nullptr;
        while (nullptr != root) {
            if (value != root->data) {
                if (nullptr == start) {
                    start = root;
                    tmp1 = start;
                }
                else {
                    tmp1->next = root;
                    tmp1 = tmp1->next;
                }
            }
            else {
                if (nullptr == tail) {
                    tail = root;
                    tmp2 = tail;
                }
                else {
                    tmp2->next = root;
                    tmp2 = tmp2->next;
                }
            }
            root = root->next;
        }
        tmp2->next = nullptr;
        tmp1->next = tail;
        return start;
    }

    template<typename T>
    Node<int>* __move_all_occurrences_to_th_end_GOOD_BEST(Node<T>* root, const T value)
    {
        Node<T> *node1 {nullptr}, *start { nullptr }, *node2 {nullptr}, *tail {  nullptr };
        while (root)
        {
            if (value != root->data) {
                if (!node1)
                    start = node1 = root;
                else {
                    node1->next = root;
                    node1 = node1->next;
                }
            }
            else {
                if (!node2)
                    tail = node2 = root;
                else {
                    node2->next = root;
                    node2 = node2->next;
                }
            }
            root = root->next;
        }

        node2->next = nullptr;
        node1->next = tail;

        return start;
    }



    template<typename T>
    Node<int>* __move_all_occurrences_to_th_end_2(Node<T>* root, T value) {
        assert(nullptr != root);
        Node<int>* start = nullptr, * tmp1 = nullptr;
        Node<int>* tail = nullptr, * tmp2 = nullptr;
        while (nullptr != root) {
            if (value != root->data) {
                if (nullptr == start) {
                    start = root;
                    tmp1 = start;
                }
                else {
                    tmp1->next = root;
                    tmp1 = tmp1->next;
                }
            }
            else {
                if (nullptr == tail) {
                    tail = root;
                    tmp2 = tail;
                }
                else {
                    tmp2->next = root;
                    tmp2 = tmp2->next;
                }
            }
            root = root->next;
        }
        tmp2->next = nullptr;
        tmp1->next = tail;
        return start;
    }

    template<typename T>
    Node<int>* __move_all_occurrences_to_th_end_TEST(Node<T>* root,
                                                     T value)
    {
        Node<T>* tailRoot, *tail = nullptr;
        if (value == root->data) {
            tail = (tailRoot = root);
            root = root->next;
        }

        Node<T>* previous = root, * current = root ? root->next : nullptr;
        while (nullptr != current) {
            if (value == current->data) {
                previous->next = current->next;
                if (!tail)
                    tail = (tailRoot = current);
                else {
                    tail->next = current;
                    tail = tail->next;
                }
            }
            else
                previous = current;
            current = previous->next;
        }

        tail->next = nullptr;
        previous->next = tailRoot;
        return root;
    }
}

void LinkedListAlgorithms::Move_All_Occurrences_To_The_End()
{
    /*
    {
        Node<int>* list = InitList({ 2,2,2,2,3,4,5,6,7,2,2,2,8,9,10 });
        PrintList(list);
        Node<int>* result = __move_all_occurrences_to_th_end(list, 2);
        PrintList(result);
    }
    */

    /** Best solution so far**/
    {
        Node<int>* list = InitList({2,2,2,1,1});
        PrintList(list);
        Node<int>* result = __move_all_occurrences_to_th_end_GOOD_BEST(list, 2);
        PrintList(result);
    }


    /*
    {
        Node<int>* list = InitList({ 2,2,2,2,3,4,5,6,7,2,2,2,8,9,10 });
        PrintList(list);
        Node<int>* result = __move_all_occurrences_to_th_end_2(list, 2);
        PrintList(result);
    }
    {
        Node<int>* list = InitList({ 2,2,2,2,3,4,5,6,7,2,2,2,8,9,10 });
        //PrintList(list);
        Node<int>* result = __move_all_occurrences_to_th_end_TEST(list, 2);
        PrintList(result);

    }
    */
}