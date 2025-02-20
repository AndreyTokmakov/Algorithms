/**============================================================================
Name        : Check_Is_Tree_Balanced.cpp
Created on  : 20.01.2025
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

    int get_depth(const Node* root)
    {
        if (!root)
            return 0;

        std::queue<const Node*> queue( {root});
        int depth = 1;
        while (!queue.empty())
        {
            for (int size = queue.size(); size > 0; --size)
            {
                const Node* node = queue.front();
                queue.pop();

                if (node->left)
                    queue.push(node->left);
                if (node->right)
                    queue.push(node->right);
            }
            ++depth;
        }
        return depth - 1;
    }

    int depth(BinTree::Node* node)
    {
        if (nullptr == node)
            return 0;
        return 1  + std::max(depth(node->left), depth(node->right));
    }

    bool is_balanced(BinTree::Node* node)
    {
        if (nullptr == node)
            return true;
        return 1 >= std::abs(depth(node->left) - depth(node->right)) &&
                is_balanced(node->left) &&
                is_balanced(node->right);
    }

}

namespace TreesAlgorithms::Tests
{
    void one_True()
    {
        BinTree::Node* root = new BinTree::Node(10);
        root->right = new BinTree::Node(20);
        root->right->left = new BinTree::Node(12);
        root->right->right = new BinTree::Node(25);
        // root->right->right->right = new BinTree::Node(35);
        root->left = new BinTree::Node(2);

        std::cout << "Balanced: " << std::boolalpha << is_balanced(root) << std::endl;
    }

    void two_True()
    {
        BinTree::Node* root = new BinTree::Node(3);
        root->left = new BinTree::Node(9);
        root->right = new BinTree::Node(20);
        root->right->left = new BinTree::Node(15);
        root->right->right = new BinTree::Node(7);

        std::cout << "Balanced: " << std::boolalpha << is_balanced(root) << std::endl;
    }

    void two_False()
    {
        BinTree::Node* root = new BinTree::Node(1);
        root->left = new BinTree::Node(2);
        root->right = new BinTree::Node(2);
        root->left->left = new BinTree::Node(3);
        root->left->right = new BinTree::Node(3);
        root->left->left->left = new BinTree::Node(4);
        root->left->left->right = new BinTree::Node(4);

        std::cout << "Balanced: " << std::boolalpha << is_balanced(root) << std::endl;
    }
}

void TreesAlgorithms::Check_Is_Tree_Balanced()
{
    Tests::one_True();
    Tests::two_True();
    Tests::two_False();
}