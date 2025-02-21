/**============================================================================
Name        : Merge_K_Sorter_Lists.cpp
Created on  : 20.01.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../LinkedListAlgorithms.h"

#include <queue>

namespace
{
    using namespace LinkedListAlgorithms;
    using ListNode = Node<int>;

    bool compare_node(const ListNode* const a,
                      const ListNode* const b)
    {
        return a->data < b->data;
    }



    ListNode* mergeKLists(std::vector<ListNode*>& lists)
    {
        std::vector<ListNode*> vec;
        for (ListNode* node : lists) {
            while (node) {
                vec.push_back(node);
                node = node->next;
            }
        }

        std::sort(vec.begin(), vec.end(), compare_node);

        ListNode res(0);
        ListNode* p = &res;
        for (ListNode* node : vec) {
            node->next = nullptr;
            p->next = node;
            p = node;
        }
        return res.next;
    }

    ListNode *mergeKLists2(const std::vector<ListNode*>& lists)
    {
        auto comparator = [](const ListNode* const a, const ListNode* const b) {
            return a->data > b->data;
        };

        std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(comparator)> nodeQueue;
        for (ListNode* list : lists) {
            nodeQueue.push(list);
        }

        ListNode res(0);
        ListNode* p = &res;
        while (!nodeQueue.empty()) {
            ListNode* smallestTopNode = nodeQueue.top();
            nodeQueue.pop();
            if (smallestTopNode->next)
                nodeQueue.push(smallestTopNode->next);
            smallestTopNode->next = nullptr;
            p->next = smallestTopNode;
            p = smallestTopNode;
        }
        return res.next;
    }

}

void LinkedListAlgorithms::Merge_K_Sorter_Lists()
{
    {
        std::vector<ListNode*> lists {
            InitList({ 1, 4, 7 }), InitList({ 2, 5, 8 }), InitList({ 3, 6, 9 })
        };
        const auto result = mergeKLists(lists);
        PrintList(result);
    }
    {
        std::vector<ListNode*> lists {
            InitList({ 1, 4, 7 }), InitList({ 2, 5, 8 }), InitList({ 3, 6, 9 })
        };
        const auto result = mergeKLists2(lists);
        PrintList(result);
    }
}
