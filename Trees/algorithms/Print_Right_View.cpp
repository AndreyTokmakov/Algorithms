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

    void print_right_view_recursive(const BinTree::Node* node,
                                    std::map<int, int>& map,
                                    const size_t level)
    {
        if (nullptr == node)
            return;

        print_right_view_recursive(node->right, map, level + 1);
        map.emplace(level, node->data);
        print_right_view_recursive(node->left, map, level + 1);
    }

    void print_right_view_recursive(const BinTree::Node* node)
    {
        std::map<int, int> map;
        print_right_view_recursive(node, map, 0);

        for (auto it : map)
            std::cout << it.second << " ";
    }

    struct Item
    {
        const Node* node {nullptr };
        int level { 0 };
    };

    void print_right_view(const BinTree::Node* root)
    {
        if (!root )
            return;

        std::map<int, int> map;
        std::vector<Item> stack {};
        Item item = {root, 0};
        while (item.node || !stack.empty())
        {
            while (item.node) {
                stack.push_back(item);
                item = {item.node->right, item.level + 1};
            }

            item = stack.back();
            stack.pop_back();

            map.emplace(item.level, item.node->data);
            item = {item.node->left, item.level + 1};
        }

        for (auto it : map)
            std::cout << it.second << " ";
    }
}

void TreesAlgorithms::Print_Right_View()
{   //                 33                 |      33
    //            22          85          |      85
    //       10       30           125    |      125
    //    6      23                       |      23

    const BinTree::Node* tree = BinTree::makeTree( { 33,  22,85,  10,30, 125, 6, 23 });

    print_right_view_recursive(tree); // 33 85 125 23
    std::cout << std::endl;
    print_right_view(tree);            // 33 85 125 23
}
















