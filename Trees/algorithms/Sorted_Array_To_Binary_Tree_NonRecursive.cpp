/**============================================================================
Name        : Sorted_Array_To_Binary_Tree_NonRecursive.cpp
Created on  : 16.01.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../TreesAlgorithms.h"

namespace
{
    using namespace TreesAlgorithms;

    void level_order_traversal(const BinTree::Node* node,
                               std::map<int, std::vector<int>>& lvls,
                               size_t level = 0) {
        if (nullptr == node)
            return;

        lvls[level].push_back(node->data);
        level_order_traversal(node->left, lvls, level + 1);
        level_order_traversal(node->right, lvls, level + 1);
    }

    void print(const BinTree::Node* node)
    {
        std::map<int, std::vector<int>> lvls;
        level_order_traversal(node, lvls);

        for (const auto& [key, values] : lvls) {
            for (const auto& v : values)
                std::cout << v << " ";
            std::cout << std::endl;
        }
    }

    BinTree::Node *sortedArrayToBST_NonRecur(const std::vector<int> &nums)
    {
        if (nums.empty())
            return nullptr;

        const long size = std::ssize(nums);
        long mid = size / 2;
        auto* root = new BinTree::Node{ nums[mid]};

        std::queue<std::pair<BinTree::Node*, std::pair<long, long>>> queue;

        // push the root and its indices to the queue
        queue.push({ root, { 0, mid - 1 } });
        queue.push({ root, { mid + 1, size - 1 } });

        while (!queue.empty())
        {
            // get the front element from the queue
            auto [parent, indices] = queue.front();
            queue.pop();

            const long left = indices.first, right = indices.second;
            // if there are elements to process and parent node is not NULL
            if (left <= right && parent)
            {
                const long mid_tmp = (left + right) / 2;

                // set the child node as left or right child of the parent node
                auto* child = new BinTree::Node{ nums[mid_tmp]};
                if (nums[mid_tmp] < parent->data)
                    parent->left = child;
                else
                    parent->right = child;

                queue.push({ child, { left, mid_tmp - 1 } });
                queue.push({ child, { mid_tmp + 1, right } });
            }
        }

        return root;
    }
}

void TreesAlgorithms::Sorted_Array_To_Binary_Tree_NonRecursive()
{
    const std::vector<int> data{ 1,2,3,4,5,6,7,8,9 };
    BinTree::Node* root = sortedArrayToBST_NonRecur(data);

    print(root);
}