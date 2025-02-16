/**============================================================================
Name        : Largest_Element_In_Each_Level.cpp
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

    std::vector<int> _largest_values(const Node* root)
    {
        std::vector<int> res;
        if (!root)
            return res;

        std::queue<const Node*> queue ({root});
        while (!queue.empty())
        {
            int maxVal = std::numeric_limits<int>::min();
            for (size_t idx = 0, size = queue.size(); idx < size; idx++)
            {
                const Node* node = queue.front();
                queue.pop();

                maxVal = std::max(maxVal, node->data);
                if (node->left)
                    queue.push(node->left);
                if (node->right)
                    queue.push(node->right);
            }
            res.push_back(maxVal);
        }
        return res;
    }

    void largest_value_in_each_level(const Node* node,
                                     std::vector<int>& levels,
                                     size_t level)
    {
        if (nullptr == node)
            return;

        int& maxElement = (level + 1) > levels.size() ? levels.emplace_back(std::numeric_limits<int>::min()) : levels[level];
        maxElement = std::max(maxElement, node->data);

        largest_value_in_each_level(node->left, levels, level + 1);
        largest_value_in_each_level(node->right, levels, level + 1);
    }

    void largest_value_in_each_level(const Node* node)
    {
        std::vector<int> levels;
        largest_value_in_each_level(node, levels, 0);

        for (const int val : levels) {
            std::cout << val << " ";
            std::cout << std::endl;
        }
    }
}

void TreesAlgorithms::Largest_Element_In_Each_Level()
{    /**
          10
        /    \
       5      15
      / \       \
    3    7       12
    **/
    Node* tree = BinTree::makeTree( { 10, 5, 15, 3, 7, 12 });
    largest_value_in_each_level(tree);  // 10 15 12

    const std::vector<int> maximums = _largest_values(tree);  // 10 15 12
    std::cout << maximums << std::endl;
}
