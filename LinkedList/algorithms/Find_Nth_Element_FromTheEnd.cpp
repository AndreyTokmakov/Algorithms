/**============================================================================
Name        : Find_Nth_Element_FromTheEnd.cpp
Created on  : 14.01.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../LinkedListAlgorithms.h"


namespace
{
    using namespace LinkedListAlgorithms;


    template<typename T>
    Node<T>* _find_Nth_element_from_the_end(Node<T>* root, int N)
    {
        Node<T>* node = root, * tmp = root;
        while (nullptr != root) {
            if (0 > N--)
                node = node->next;
            root = root->next;
        }
        return tmp == node ? nullptr : node;
    }

    template<typename T>
    Node<T>* _find_Nth_element_from_the_end_EX(Node<T>* root, int N)
    {
        Node<T>* node = root, *tmp = root;
        while (node && N--)
            node = node->next;
        while (node) {
            node = node->next;
            tmp = tmp->next;
        }
        return tmp;
    }

    template<typename T>
    std::optional<Node<T>*> _find_Nth_element_from_the_end_Opt(Node<T>* root, int N)
    {
        Node<T>* node = nullptr, * tmp = root;
        while (nullptr != root) {
            if (0 >= N--)
                node = (nullptr == node) ? tmp : node->next;
            root = root->next;
        }
        return nullptr == node ? std::nullopt : std::make_optional<Node<T>*>(node);
    }

}

void LinkedListAlgorithms::Find_Nth_Element_FromTheEnd()
{
    Node<int>* root = InitList({ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 });
    constexpr int K = 1;

    {
        Node<int>* result = _find_Nth_element_from_the_end(root, K);
        if (nullptr == result)
            std::cout << "None" << std::endl;
        else
            std::cout << result->data << std::endl;
    }
    {
        std::optional<Node<int>*> result = _find_Nth_element_from_the_end_Opt(root, K);
        if (result.has_value())
            std::cout << result.value()->data << std::endl;
        else
            std::cout << "None" << std::endl;
    }
    {
        Node<int>* result = _find_Nth_element_from_the_end_EX(root, K);
        if (nullptr == result)
            std::cout << "None" << std::endl;
        else
            std::cout << result->data << std::endl;
    }
}