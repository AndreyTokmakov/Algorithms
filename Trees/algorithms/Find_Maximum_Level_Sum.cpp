/**============================================================================
Name        : Find_Maximum_Level_Sum.cpp
Created on  : 26.02.2025
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
}

namespace TreesAlgorithms::Recursive_Vector
{
    void find_maximum_level_sum(const BinTree::Node* node,
                                const size_t level,
                                std::vector<int>& levels) {
        if (nullptr == node)
            return;

        int& lvlSum = level > levels.size() ? levels.emplace_back() : levels[level - 1];
        lvlSum += node->data;

        find_maximum_level_sum(node->left, level + 1, levels);
        find_maximum_level_sum(node->right, level + 1, levels);
    }

    int max_level_sum(const BinTree::Node* node)
    {
        std::vector<int> levels;
        find_maximum_level_sum(node, 1, levels);
        return  *std::max_element(levels.begin(), levels.end());
    }
}

namespace TreesAlgorithms::Recursive_Map
{
    void find_maximum_level_sum(const BinTree::Node* node,
                                const size_t level,
                                std::map<int, int>& levels) {
        if (nullptr == node)
            return;

        levels[level] += node->data;
        find_maximum_level_sum(node->left, level + 1, levels);
        find_maximum_level_sum(node->right, level + 1, levels);
    }

    int max_level_sum(const BinTree::Node* node)
    {
        std::map<int, int> levels;
        find_maximum_level_sum(node, 1, levels);
        int result{ std::numeric_limits<int>::min() };
        for (const auto& entry : levels)
            result = std::max(result, entry.second);

        return result;
    }
}


namespace TreesAlgorithms::Good_NonRecursive
{
    int max_level_sum(const Node* root)
    {
        if (!root)
            return 0;

        int maxSum = std::numeric_limits<int>::min();
        std::queue<const Node*> queue ({root});
        while (!queue.empty())
        {
            int levelSum = 0;
            for (size_t idx = 0, size = queue.size(); idx < size; idx++)
            {
                const Node* node = queue.front();
                queue.pop();
                levelSum += node->data;

                if (node->left)
                    queue.push(node->left);
                if (node->right)
                    queue.push(node->right);
            }
            maxSum = std::max(maxSum, levelSum);
        }
        return maxSum;
    }
}

void TreesAlgorithms::Find_Maximum_Level_Sum()
{
    // const BinTree::Node* tree = BinTree::makeTree( { 333,22,85,10,30,54,125,5,13,25,35  });
    BinTree::Node* tree = BinTree::makeTree( { 33,22,85,10,30,54,125,5,12,25,32,45,60,120,130,4,3,2,12,13,14,15,16 });

    std::cout << Recursive_Vector::max_level_sum(tree) << std::endl;
    std::cout << Recursive_Map::max_level_sum(tree) << std::endl;
    std::cout << Good_NonRecursive::max_level_sum(tree) << std::endl;


}