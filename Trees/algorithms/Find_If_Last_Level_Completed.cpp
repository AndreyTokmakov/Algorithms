/**============================================================================
Name        : Find_If_Last_Level_Completed.cpp
Created on  : 04.03.2025
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

    bool find_if_last_level_is_completed(const Node* root)
    {
        if (!root || (!root->left && !root->right))
            return true;

        int level = 0, lvlElementsCount = 0;
        std::queue<const Node*> queue ({root});
        while (!queue.empty())
        {
            lvlElementsCount = 0;
            ++level;
            for (size_t idx = 0, size = queue.size(); idx < size; idx++)
            {
                const Node* node = queue.front();
                queue.pop();
                ++lvlElementsCount;

                if (node->left)
                    queue.push(node->left);
                if (node->right)
                    queue.push(node->right);
            }
        }

        // level need to be decremented  --> ( level = level -1 )
        // 0 lvl -> 1 element, 1 lvl -> 2, 2 lvl -> 4, 3 lvl -> 8 elements
        return std::log2(lvlElementsCount) == (level - 1);
    }
}

void TreesAlgorithms::Find_If_Last_Level_Completed()
{
    using TestData = std::vector<std::pair<const Node*, bool>>;
    for (const auto& [tree, expected]:  TestData{
            { BinTree::makeTree({33}) , true },
            { BinTree::makeTree({33, 22,85}) , true },
            { BinTree::makeTree({33, 22,85, 10}) , false },
            { BinTree::makeTree({33, 22,85, 10,30,54,125}) , true },
            { BinTree::makeTree({33, 22,85, 10,30}) , false },
    })
    {
        const auto actual = find_if_last_level_is_completed(tree);
        if (expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
    }
    std::cout << "OK: All tests passed\n";
}
