/**============================================================================
Name        : Add_Two_Numbers.cpp
Created on  : 15.01.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../LinkedListAlgorithms.h"

/**
You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order and each of their nodes contain a single digit.
Add the two numbers and return it as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.
Example: Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)   Output: 7 -> 0 -> 8
          Explanation: 342 + 465 = 807.
**/

namespace
{
    using namespace LinkedListAlgorithms;
    using ListNode = Node<int>;

    ListNode* addTwoNumbers(const ListNode* l1,
                            const ListNode* l2)
    {
        ListNode *pre = new ListNode(0), *cur = pre;
        for (int carry = 0; l1 || l2 || carry > 0; cur = cur->next, carry /= 10)
        {
            if (l1) {
                carry += l1->data;
                l1 = l1->next;
            }
            if (l2) {
                carry += l2->data;
                l2 = l2->next;
            }
            cur->next = new ListNode(carry % 10);
        }
        return pre->next;
    }
}

void LinkedListAlgorithms::Add_Two_Numbers()
{
    const Node<int>* list1 = InitList({ 2,4,3 });
    const Node<int>* list2 = InitList({5,6,4});
    const ListNode* result = addTwoNumbers(list1, list2);
    PrintList(result);
}
