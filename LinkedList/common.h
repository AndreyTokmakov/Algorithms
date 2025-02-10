/**============================================================================
Name        : common.h
Created on  : 10.02.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#ifndef LINKED_LIST_COMMON_H
#define LINKED_LIST_COMMON_H

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cassert>

namespace LinkedListAlgorithms
{
    template<typename T>
    struct Node
    {
        using data_type = T;

        static_assert(!std::is_same_v<data_type, void>,
                      "Type of the value shall not be void");

        data_type data;
        Node* next { nullptr };

    public:
        explicit Node(data_type value) : data { value }, next { nullptr } {
        }

        Node(data_type value, Node* nxt) : data { value }, next { nxt } {
        }

    public:
        /** Operators reload. **/
        friend std::ostream& operator<<(std::ostream& stream, const Node<data_type>& node);
    };

    template<typename T>
    std::ostream& operator<<(std::ostream& stream, const Node<T>& node)
    {
        stream << node.data;
        return stream;
    }

    template<typename T>
    void PrintList(const Node<T>* root, const std::string& text = "\n")
    {
        auto* node = const_cast<Node<T>*>(root);
        while (nullptr != node) {
            std::cout << node->data << " ";
            node = node->next;
        }
        std::cout << text;
    }

    template<typename Type>
    Node<Type>* InitList(std::initializer_list<Type> args)
    {
        assert(std::size(args) > 0), "List expects to have more than one element";
        Node<Type>* root = new Node<Type>(*std::begin(args)), * node = root;
        for (const Type* it = std::begin(args) + 1; it != std::end(args); ++it) {
            node->next = new Node(*it);
            node = node->next;
        }
        return root;
    }

    template<typename Type>
    Node<Type>* InitList(const std::vector<Type>& data)
    {
        assert(std::size(data) > 0), "List expects to have more than one element";
        Node<Type>* root = new Node<Type>(data.front()), * node = root;
        for (size_t idx = 1; idx < data.size(); ++idx) {
            node->next = new Node(data[idx]);
            node = node->next;
        }
        return root;
    }
}

#endif //LINKED_LIST_COMMON_H

