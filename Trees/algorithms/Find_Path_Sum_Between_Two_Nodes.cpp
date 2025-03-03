/**============================================================================
Name        : Find_Path_Sum_Between_Two_Nodes.cpp
Created on  : 03.03.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../TreesAlgorithms.h"

namespace {
    using namespace TreesAlgorithms;

}

namespace Good
{

    const BinTree::Node* get_lowest_common_ancestor(const BinTree::Node* node,
                                                    const int x1,
                                                    const int x2)
    {
        while (nullptr != node)
        {
            if (x1 > node->data && x2 > node->data) {
                node = node->right;
            }
            else if (x1 < node->data && x2 < node->data) {
                node = node->left;
            }
            else
                return node;
        }
        return  node ;
    }

    int calc_path(const BinTree::Node* node,
                     const int x1)
    {
        int dist = 0;
        while (nullptr != node) {
            if (x1 > node->data) {
                dist++;
                node = node->right;
            }
            else if (x1 < node->data) {
                dist++;
                node = node->left;
            }
            else return dist;
        }
        return dist;
    }

    int find_pathSum_between_nodes(const BinTree::Node* node,
                                   const int x1,
                                   const int x2)
    {
        const BinTree::Node* lcaNode = get_lowest_common_ancestor(node, x1, x2);
        return calc_path(lcaNode, x1) + calc_path(lcaNode, x2);
    }
}

namespace Recursive
{
    const BinTree::Node* get_lowest_common_ancestor(const BinTree::Node* node,
                                                    const int x1,
                                                    const int x2)
    {
        if (nullptr == node)
            return nullptr;
        else if (x1 > node->data && x2 > node->data)
            return get_lowest_common_ancestor(node->right, x1, x2);
        else if (x1 < node->data && x2 < node->data)
            return get_lowest_common_ancestor(node->left, x1, x2);
        else
            return node;
    }

    int calc_path(const BinTree::Node* node,
                  const int x)
    {
        if (nullptr == node || x == node->data)
            return 0;
        else if (x > node->data)
            return 1 + calc_path(node->right, x);
        else if (x < node->data)
            return 1 + calc_path(node->left, x);
        return 0;
    }

    int find_pathSum_between_nodes(const BinTree::Node* node,
                                   const int x1,
                                   const int x2)
    {
        const BinTree::Node* lcaNode = get_lowest_common_ancestor(node, x1, x2);
        return calc_path(lcaNode, x1) + calc_path(lcaNode, x2);
    }
}

void TreesAlgorithms::Find_Path_Sum_Between_Two_Nodes()
{
    using TestData = std::vector< std::pair<  std::pair<const Node*, std::pair<int,int>     >, int> >;
    for (const auto& [data, expected]:  TestData{
            { {BinTree::makeTree({33,22,85,10,25,54,125,5,15,30 }) , {10 , 125}}, 4 },
            { {BinTree::makeTree({33,22,85}) , {22 , 85}}, 2 },
    })
    {
        auto actual = Good::find_pathSum_between_nodes(data.first, data.second.first, data.second.second );
        if (expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }

        actual = Recursive::find_pathSum_between_nodes(data.first, data.second.first, data.second.second );
        if (expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
    }
    std::cout << "OK: All tests passed\n";
}