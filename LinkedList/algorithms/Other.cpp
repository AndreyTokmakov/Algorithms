/**============================================================================
Name        : Other.cpp
Created on  : 14.01.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description : LinkedList algorithms entry point
============================================================================**/

#include "../common.h"
#include "../LinkedListAlgorithms.h"

#include <unordered_set>
#include <forward_list>

namespace LinkedListAlgorithms
{

    template<typename T>
    Node<T>* _reserve_sublists(Node<T>* head) {
        Node<int>* next = head;

        while (nullptr != next) {
            if (0 == next->data % 2) {
            }
            next = next->next;
        }
        std::cout << std::endl;
        return head;
    }

    void Reverse_Sublists_Operations() {
        Node<int>* list = InitList({ 1, 2, 8, 9, 12, 16 });
        PrintList(list);
        Node<int>* result = _reserve_sublists(list);
        PrintList(result);
    }

    //----------------------------------------------------------------------//

    template<typename T>
    Node<T>* _make_reverse_list(Node<T>* root) {
        Node<int>* prev = new Node<int>(root->data);

        Node<int>* node = root->next;
        while (nullptr != node) {
            Node<int>* current = new Node<int>(node->data, prev);
            prev = current;
            node = node->next;
        }
        return prev;
    }

    void Make_Reversed_FromList() {
        Node<int>* root = InitList({ 1,2,3,4,5,6,7,8,9 });

        PrintList(root);
        root = _make_reverse_list(root);
        PrintList(root);
    }



    template<typename T>
    Node<int>* _move_to_the_end(Node<T>* root, const T value) {
        while (nullptr != root && value == root->data)
            root = root->next;

        Node<T>* tail = nullptr;
        Node<T>* current = root, * previous = nullptr;
        while (nullptr != current) {
            if (value == current->data) {
                previous->next = current->next;
                if (nullptr == tail)
                    tail = current;
                else
                    tail->next = current;
            }
            else {
                previous = current;
            }
            current = previous->next;
        }

        std::cout << previous->data << std::endl;

        return root;
    }


    void MoveAllOccurrencesToTheEnd_TEST() {
        Node<int>* list = InitList({ 2,2,2,2,3,4,5,6,7,2,2,2,8,9,10 });
        PrintList(list);
        list = _move_to_the_end(list, 2);
        PrintList(list);
    }

    //----------------------------------------------------------------------//

    void Reverse_Even_Subarrays()
    {
        Node<int>* list = InitList({ 2, 18, 24, 3, 5, 7, 9, 6, 12 }); // -> 24, 18, 2, 3, 5, 7, 9, 12, 6
        Node<int>* node = list;

        Node<int>* start = nullptr, * end = nullptr;
        std::vector<int> values;
        while (nullptr != node) {
            std::cout << node->data << std::endl;

            if (0 == node->data % 2) {
                values.push_back(node->data);
                if (nullptr == start)
                    start = node;
                end = node;
            }
            else {
                std::reverse(values.begin(), values.end());
                for (int i : values) {
                    start->data = i;
                    start = start->next;
                }
                start = nullptr;
                end = nullptr;
                values.clear();
            }
            node = node->next;
        }

        std::reverse(values.begin(), values.end());
        for (int i : values) {
            start->data = i;
            start = start->next;
        }
    }

}

namespace LinkedListAlgorithms::JustTests
{

    // Delete node by values
    template<typename T>
    Node<int>* _delete_node_(Node<T>* root, const T value) {
        while (nullptr != root && root->data == value)
            root = root->next;

        Node<int>* previous = root, * current = root ? root->next : nullptr;
        while (nullptr != current) {
            if (value == current->data)
                previous->next = current->next;
            else
                previous = current;
            current = previous->next;
        }
        return root;
    }

    // Delete node by values
    template<typename T>
    Node<int>* _reverse_(Node<T>* node) {
        Node<int>* previous = nullptr, * next = node;
        while (nullptr != node) {
            next = node->next;

            node->next = previous;
            previous = node;

            node = next;
        }
        return previous;
    }

    template<typename T>
    Node<T>* _reverse_test(Node<T>* root) {
        // void  _reverse_test(Node<T>* root) {
        assert(nullptr != root);
        Node<int>* previous = nullptr, * next = nullptr, * node = root;
        while (nullptr != node) {
            next = node->next;
            node->next = previous;
            previous = node;
            node = next;
        }
        return previous;
    }

    template<typename T>
    Node<T>* _reverse_test_rec(Node<T>* root, Node<T>* prev = nullptr) {
        root->next->next = prev;
        return root->next;
    }

    void SOME_TESTS() {
#if 0   // Delete list test //
        Node<int>* list = InitList({ 5,1,5,5,2,4,5,5,5,7,8,9 });
		PrintList(list);
		list = _delete_node_(list, 5);
		PrintList(list);
#endif

#if 0   // Reverse list test 1 //
        Node<int>* list = InitList({ 1,2,3,4,5 });
		PrintList(list);
		list = _reverse_(list);
		PrintList(list);
		std::cout << "Done" << std::endl;
#endif

#if 0   // Reverse list test 2 //
        Node<int>* list = InitList({ 1,2,3,4,5,6,7,8,9 });
		PrintList(list);
		list = _reverse_test(list);
		PrintList(list);
		std::cout << "Done" << std::endl;
#endif



        auto* root = new Node<int>(0);;
        Node<int>* node = root;

        for (int i = 1; i < 10; ++i)
        {
            node->next = new Node<int>(i);
            node = node->next;
        }

        PrintList(root);

    }
}



void LinkedListAlgorithms::Other() {

}