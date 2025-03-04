/**============================================================================
Name        : Trees.h
Created on  : 13.02.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#ifndef TREES_ALGORITHMS_COMMON_H
#define TREES_ALGORITHMS_COMMON_H

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <list>
#include <map>
#include <unordered_map>
#include <queue>
#include <deque>
#include <cassert>
#include <cmath>


namespace BinTree
{
    struct Node
    {
        int data { 0 };
        Node* left { nullptr };
        Node* right { nullptr };

        explicit Node(const int value, Node* l = nullptr, Node* r = nullptr):
            data {value}, left {l}, right {r} {
        }

        [[nodiscard]]
        int getData() const noexcept {
            return data;
        }
    };

    inline Node* insert(const int value, Node* node)
    {
        if (nullptr == node) {
            node = new Node(value);
        }
        else if (value < node->data) {
            node->left = insert(value, node->left);
        }
        else if (value > node->data) {
            node->right = insert(value, node->right);
        }
        return node;
    }

    [[nodiscard]]
    inline Node* makeTree(const std::initializer_list<int> list)
    {
        Node* root { nullptr };
        for (const int value : list)
            root = insert(value, root);
        return root;
    }

    [[nodiscard]]
    inline Node* makeTreeNonBST(int rootVal, const std::initializer_list<int> list)
    {
        Node* root { new Node(rootVal) }, *result = root;
        for (const int value : list) {
            root->left = new Node(value);
            root = root->left;
        }
        return result;
    }
}

namespace TreesAlgorithms
{
    template<typename T>
    std::ostream& operator<<(std::ostream& stream, const std::vector<T>& vect) {
        for (const T& entry : vect)
            stream << entry << ' ';
        return stream;
    }

    template<typename T>
    std::ostream& operator<<(std::ostream& stream, const std::list<T>& vect) {
        for (const T& entry : vect)
            stream << entry << ' ';
        return stream;
    }

    using Node = BinTree::Node;
}


#endif //TREES_ALGORITHMS_COMMON_H

