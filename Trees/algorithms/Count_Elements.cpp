/**============================================================================
Name        : Count_Elements.cpp
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

    int count_recursive(const BinTree::Node *root) {
        return root == nullptr ? 0 : 1 + count_recursive(root->left) + count_recursive(root->right);
    }


    int count(const Node *root)
    {
        if (!root)
            return 0;

        std::queue<const Node*> queue( {root});
        int count = 1;
        while (!queue.empty()) {
            const Node* node = queue.front();
            queue.pop();

            if (nullptr != node->left) {
                queue.push(node->left);
                ++count;
            }
            if (nullptr != node->right) {
                queue.push(node->right);
                ++count;
            }
        }
        return count;
    }

}

void TreesAlgorithms::Count_Elements()
{
    Node* tree = BinTree::makeTree( { 10, 5, 15, 3, 7, 12 });
    std::cout << count_recursive(tree) << std::endl;
    std::cout << count(tree) << std::endl;

}