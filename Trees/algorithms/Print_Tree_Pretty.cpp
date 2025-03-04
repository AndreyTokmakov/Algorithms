/**============================================================================
Name        : Print_Tree_Pretty.cpp
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


    void print_tree(const Node* root)
    {
        if (!root)
            return;

        std::vector<std::vector<std::optional<int>>> levels;
        size_t size = 1, optCount = 0;
        std::queue<std::optional<const Node*>> queue ({root});
        while (!queue.empty() && size != optCount)
        {
            size = queue.size(), optCount = 0;
            std::vector<std::optional<int>>& level = levels.emplace_back();
            for (size_t idx = 0; idx < size; idx++)
            {
                const std::optional<const Node*> optNode = queue.front();
                queue.pop();

                if (optNode.has_value())
                {
                    if (optNode.value()->left)
                        queue.emplace(optNode.value()->left);
                    else
                        queue.emplace(std::nullopt);

                    if (optNode.value()->right)
                        queue.emplace(optNode.value()->right);
                    else
                        queue.emplace(std::nullopt);

                    level.emplace_back(optNode.value()->data);
                }
                else
                {
                    level.emplace_back();
                    queue.emplace(std::nullopt);
                    queue.emplace(std::nullopt);
                    ++optCount;
                }
            }
        }

        levels.pop_back();
        const size_t lvlCount = levels.size();

        for (const std::vector<std::optional<int>>& level : levels)
        {
            for (const std::optional<int> node : level)
            {
                if (node.has_value())
                    std::cout << node.value() << " ";
                else
                    std::cout <<  "[] ";
            }
            std::cout << std::endl;
        }
    }

}

void TreesAlgorithms::Print_Tree_Pretty()
{
    BinTree::Node* tree = BinTree::makeTree( { 33,  22,85,  10,30, 125, 6, 23 });
    // BinTree::Node* tree = BinTree::makeTree( { 33,  22,85,  10,30,125 });
    print_tree(tree);

    /*std::vector<std::optional<int>> level;
    level.emplace_back(5);
    std::cout << level.back().value_or(111) << std::endl;*/
}
