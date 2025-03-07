/**============================================================================
Name        : Print_Right_View.cpp
Created on  : 06.03.2025
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

    void print_right_view(const BinTree::Node* node,
                          std::map<int, int>& map,
                          const size_t level)
    {
        if (nullptr == node)
            return;

        print_right_view(node->right, map, level + 1);
        map.emplace(level, node->data);
        print_right_view(node->left, map, level + 1);
    }

    void print_right_view(BinTree::Node* node)
    {
        std::map<int, int> map;
        print_right_view(node, map, 0);

        for (auto it : map)
            std::cout << it.second << " ";
    }
    struct Item
    {
        const Node* node;
        int depth;
    };

    void print_right_view_test(BinTree::Node* root)
    {
        if (!root )
            return;

        std::vector<Item> stack {};
        Item item = stack.emplace_back(root, 1);
        while (stack.empty())
        {
            while (item.node) {
                item = stack.emplace_back(item.node->right, item.depth + 1);
            }

            item = stack.back();
            stack.pop_back();

            std::cout << item.node->data << " " << item.depth << std::endl;
            item = stack.emplace_back(item.node->right, item.depth + 1);
        }
    }

}

void TreesAlgorithms::Print_Right_View()
{
    //                 33                 |      33
    //            22          85          |      85
    //        10     30            125    |      125
    //      6      23                     |      23

    BinTree::Node* tree = BinTree::makeTree( { 33,  22,85,  10,30, 125, 6, 23 });
    // print_right_view(tree); // 33 85 125 23

    print_right_view_test(tree);
}
















