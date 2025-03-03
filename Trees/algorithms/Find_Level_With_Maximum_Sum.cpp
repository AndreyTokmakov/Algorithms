/**============================================================================
Name        : Find_Level_With_Maximum_Sum.cpp
Created on  : 03.03.2025
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

    std::vector<int> find_level_with_maximum_sum(const Node* root)
    {
        if (!root)
            return {};

        int maxLevelSum = 0, currLevelSum = 0;
        std::vector<int> maxLevel {}, currLevel {};
        std::queue<const Node*> queue ({root});
        while (!queue.empty())
        {
            for (size_t idx = 0, size = queue.size(); idx < size; idx++)
            {
                const Node* node = queue.front();
                queue.pop();
                currLevelSum += currLevel.emplace_back(node->data);

                if (node->left)
                    queue.push(node->left);
                if (node->right)
                    queue.push(node->right);
            }
            if (currLevelSum > maxLevelSum)
            {
                std::swap(maxLevel, currLevel);
                std::swap(maxLevelSum, currLevelSum);
                currLevelSum = 0;
                currLevel.clear();
            }
        }
        return maxLevel;
    }
}

void TreesAlgorithms::Find_Level_With_Maximum_Sum()
{
    using TestData = std::vector<std::pair<const Node*, std::vector<int>>>;
    for (const auto& [tree, expected]:  TestData{
        {BinTree::makeTree({33,22,85,10,25,54}), {22, 85} },
        {BinTree::makeTree({33,22,85,10,25,54,125}), {10,25,54,125} }
    })
    {
        auto actual = find_level_with_maximum_sum(tree);
        if (expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << expected << std::endl;
        }
    }
    std::cout << "OK: All tests passed\n";
}