/**============================================================================
Name        : Find_N_th_Smallest_Element.cpp
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

    Node* find_min_Nth_element_non_recursive(Node *node, size_t k)
    {
        std::vector<Node *> stack{};
        Node *curr = node, *min = nullptr;

        while (nullptr != curr || !stack.empty()) {
            while (nullptr != curr) {
                stack.push_back(curr);
                curr = curr->left;
            }

            curr = stack.back();
            stack.pop_back();
            min = curr;

            if (0 == --k)
                break;
            curr = curr->right;
        }
        return min;
    }


}

void TreesAlgorithms::Find_N_th_Smallest_Element()
{   /**
                   33
             22              85
       10       30      54       125
    5     8   25  32 45   60  120   130
    **/
    Node* tree = BinTree::makeTree( {  33,22,85,10,30,54,125,5,8,25,32,45,60,120,130  });
    size_t K = 4;
    auto res = find_min_Nth_element_non_recursive(tree, K);  // --> 22
    std::cout << res->data << std::endl;
}