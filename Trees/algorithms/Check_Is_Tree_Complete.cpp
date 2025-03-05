/**============================================================================
Name        : Check_Is_Tree_Complete.cpp
Created on  : 05.03.2025
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

    [[nodiscard]]
    bool is_tree_complete(const Node* root)
    {
        if (!root || (!root->left && !root->right))
            return true;

        std::queue<std::optional<const Node*>> queue ({root});
        for (int level = 0, missingCount = 0; !queue.empty(); ++level)
        {
            missingCount = 0;
            for (size_t idx = 0, size = queue.size(); idx < size; idx++)
            {
                const std::optional<const Node*> optNode = queue.front();
                queue.pop();

                if (optNode.has_value())
                {   /// If we have an EXISTING node on level AND we have aleady atleast one missing on the
                    /// same level -->  BST is not Complete
                    if (missingCount > 0)
                        return false;
                    if (optNode.value()->left)
                        queue.emplace(optNode.value()->left);
                    else
                        queue.emplace(std::nullopt);
                    if (optNode.value()->right)
                        queue.emplace(optNode.value()->right);
                    else
                        queue.emplace(std::nullopt);
                }
                else {
                    missingCount++;
                }
            }
        }
        return true;
    }

    bool is_tree_complete_2(const Node* root)
    {
        if (root == nullptr)
            return true;

        std::queue<const Node*> queue ({root});
        for (bool nullEncountered = false; !queue.empty();)
        {
            const Node* node = queue.front();
            queue.pop();

            if (nullptr == node) { // If we have seen a NULL node, we  set the flag to true
                nullEncountered= true;
            }
            else { // If that NULL node is not the last node then return false
                if (nullEncountered == true) {
                    return false;
                }
                // Push both nodes even if  there are null
                queue.push(node->left);
                queue.push(node->right);
            }
        }

        return true;
    }
}

void TreesAlgorithms::Check_Is_Tree_Complete()
{
    using TestData = std::vector<std::pair<const Node*, bool>>;
    for (const auto& [tree, expected]:  TestData{
             { BinTree::makeTree({}) , true },
             { BinTree::makeTree({33}) , true },
            { BinTree::makeTree({33, 22,85}) , true },
            { BinTree::makeTree({33, 22,85, 10,54,125}) , false },
            { BinTree::makeTree({33, 22,85, 10,30,54}) , true },
            { BinTree::makeTree({33, 22,85, 10,30,54,125}) , true },
            { BinTree::makeTree({33, 22,85, 10}) , true },
    })
    {
        if (const auto actual = is_tree_complete(tree); expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
        if (const auto actual = is_tree_complete_2(tree); expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
    }
    std::cout << "OK: All tests passed\n";
}