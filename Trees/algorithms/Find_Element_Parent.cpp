/**============================================================================
Name        : Find_Element_Parent.cpp
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

    std::optional<const BinTree::Node*> find_node(const BinTree::Node* root,
                                                  const int value)
    {
        for (const BinTree::Node* node = root, *parent = nullptr; nullptr != node;)
        {
            if (value == node->data)
                return parent;
            parent = node;
            node = (value > node->data) ? node->right : node->left;
        }
        return std::nullopt;
    }
}

void TreesAlgorithms::Find_Element_Parent()
{
    using TestData = std::vector<std::pair< std::pair<const Node*,int>, std::optional<int>>>;
    for (const auto& [data, expected]:  TestData {
        { {BinTree::makeTree({33, 22,85}) , 22 }, 33 },
        { {BinTree::makeTree({33, 22,85, 10,25,54,125}) , 25 }, 22 },
        { {BinTree::makeTree({33, 22,85, 10,25,54,125, 5,15,30}) , 15 }, 10 },
    }){
        const auto actual = find_node(data.first, data.second);

        if (!expected.has_value() && actual.has_value()) {
            std::cerr << "ERROR: Expected result -> std::nullopt" << std::endl;
        } else if (expected.has_value() && !actual.has_value()) {
            std::cerr << "ERROR: Actual result -> std::nullopt" << std::endl;
        }

        if (expected.has_value() && expected.value() != actual.value()->data) {
            std::cerr << std::boolalpha << expected.value() << " != " << actual.value()->data << std::endl;
        }
    }
    std::cout << "OK: All tests passed\n";
}