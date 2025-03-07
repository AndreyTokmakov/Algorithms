/**============================================================================
Name        : Print_Top_View.cpp
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

    void print_top_view(BinTree::Node* node,
                         std::map<size_t, std::pair<size_t, size_t>>& map,
                         size_t level,
                         const size_t distance) {
        if (nullptr == node)
            return;

        // if current level is less than maximum level seen so far for the same horizontal
        // distance or horizontal distance is seen for the first time, update the map
        if (const auto it = map.find(distance);  map.end() == it || level < it->second.second) {
            map[distance] = { node->data, level };
        }
        print_top_view(node->left, map, level + 1, distance - 1);
        print_top_view(node->right, map, level + 1, distance + 1);
    }

    void print_pop_view(BinTree::Node* node)
    {
        std::map<size_t, std::pair<size_t, size_t>> map;
        print_top_view(node, map, 0, 0);

        // traverse the map and print top view
        for (auto it : map)
            std::cout << it.second.first << " ";
    }
}

void TreesAlgorithms::Print_Top_View()
{
    //                 33
    //            22          85
    //        10     30            125
    //      6      23

    BinTree::Node* tree = BinTree::makeTree( { 33,  22,85,  10,30, 125, 6, 23 });
    print_pop_view(tree); // 33 85 125 6 10 22

}