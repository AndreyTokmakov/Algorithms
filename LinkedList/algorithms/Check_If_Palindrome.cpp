/**============================================================================
Name        : Check_If_Palindrome.cpp
Created on  : 14.01.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../LinkedListAlgorithms.h"

#include <forward_list>

namespace
{
    using namespace LinkedListAlgorithms;

    template<typename T>
    bool check_if_palindrome(const Node<T>* root)
    {
        std::forward_list<T> list;
        const Node<T>* node = root;
        while (nullptr != node) {
            list.push_front(node->data);
            node = node->next;
        }

        typename std::forward_list<T>::const_iterator iter = list.cbegin();
        node = root;
        while (nullptr != node) {
            if (node->data != *iter)
                return false;
            node = node->next;
            ++iter;
        }
        return true;
    }

    template<typename T>
    bool check_if_palindrome_2(const Node<T>* root)
    {
        std::vector<T> values;
        auto * node = root;
        while (nullptr != node) {
            values.push_back(node->data);
            node = node->next;
        }

        for (size_t idx = 0, size = values.size(); idx < size /2; ++idx)
            if (values[idx] != values[size - 1 - idx])
                return false;

        return true;
    }

    template<typename T>
    bool check_if_palindrome_3(const Node<T>* root)
    {
        int size = 0;
        std::vector<T> values;
        const Node<T>* node = root, *slow = root;
        while (nullptr != node)
        {
            values.push_back(slow->data);
            if (0 == size % 2)
                slow = slow->next;
            node = node->next;
        }

        node = root;
        for (int idx = values.size() - 1; idx > 0; --idx)
        {
            if (values[idx] != node->data)
                return false;
            node = node->next;
        }

        return true;
    }


}

void LinkedListAlgorithms::Check_If_Palindrome()
{
    for (const Node<int>* list: std::vector<Node<int>*> {
            InitList({ 1,2,3,4,5,6,7,8,9 }), InitList({ 1,2,3,2,1 })
    })
    {
        std::cout << std::boolalpha
                  << check_if_palindrome(list) << "  "
                  << check_if_palindrome_2(list) << "  "
                  << check_if_palindrome_3(list)
                  << std::endl;
    }
}