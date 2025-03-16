/**============================================================================
Name        : Check_List_Is_Cycled.cpp
Created on  : 14.01.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../LinkedListAlgorithms.h"

#include <unordered_set>

namespace
{
    using namespace LinkedListAlgorithms;

    template<typename T>
    bool check_list_is_cycled(Node<T>* root)
    {
        for (Node<int>* slow = root, *fast = root; slow && fast && fast->next;
             slow = slow->next, fast = fast->next->next)
        {
            if (slow == fast) {
                return true;
            }
        }
        return false;
    }

    template<typename T>
    bool check_list_is_cycled_2(Node<T>* root)
    {
        std::unordered_set< Node<int>*> nodes;
        for (Node<int>* node = root; nullptr != node; node = node->next) {
            if (!nodes.insert(node).second) {
                return true;
            }
        }
        return false;
    }

}

void LinkedListAlgorithms::Check_List_Is_Cycled()
{
    Node<int>* root = new Node(1), * node = root;
    for (int i = 2; i < 100; i++) {
        node->next = new Node(i);
        node = node->next;
    }
    node->next = root;

    std::cout << std::boolalpha << check_list_is_cycled(root) << std::endl;
    std::cout << std::boolalpha << check_list_is_cycled_2(root) << std::endl;
}