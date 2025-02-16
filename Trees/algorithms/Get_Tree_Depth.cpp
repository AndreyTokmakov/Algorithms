/**============================================================================
Name        : Get_Tree_Depth.cpp
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

    int get_depth_recursive(Node* node)
    {
        return nullptr == node ? 0 : 1 + std::max(get_depth_recursive(node->left), get_depth_recursive(node->right));
    }

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
}

void TreesAlgorithms::Get_Tree_Depth()
{
    {
        Node *tree = BinTree::makeTree({10, 5, 15, 3, 7, 12});
        std::cout << get_depth_recursive(tree) << std::endl;
        std::cout << get_depth(tree) << std::endl;
    }
    {
        Node* tree = BinTree::makeTree( {  33,22,85,10,30,54,125,5,8,25,32,45,60,120,130  });
        std::cout << get_depth_recursive(tree) << std::endl;
        std::cout << get_depth(tree) << std::endl;
    }
}
