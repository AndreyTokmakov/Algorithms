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
    void check_list_is_cycled(Node<T>* root)
    {
        Node<int>* slow = root, * fast = root;
        // size_t count = 0;
        while (nullptr != slow && nullptr != fast && nullptr != fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            // ++count;
            if (slow == fast) {
                std::cout << " Loop detected" << std::endl;
                // std::cout << "count = " << count << std::endl;
                break;
            }
        }
    }

    template<typename T>
    void check_list_is_cycled_2(Node<T>* root)
    {
        // size_t count = 0;
        std::unordered_set< Node<int>*> nodes;
        Node<int>* node = root;
        while (nullptr != node)  {
            // ++count;
            if (!nodes.insert(node).second)
            {
                std::cout << " Loop detected" << std::endl;
                // std::cout << "count = " << count << std::endl;
                return;
            }
            node = node->next;
        }
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

    check_list_is_cycled(root);
    check_list_is_cycled_2(root);
}