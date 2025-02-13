/**============================================================================
Name        : Stack_Using_One_Queue.cpp
Created on  : 11.02.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../StackAlgorithms.h"

#include <queue>
#include <stack>

namespace
{
    using namespace StackAlgorithms;

    struct MinStackImpl
    {
        std::stack<int> s;
        int min_element;

        // Prints minimum element:
        void getMin()
        {
            if (true == s.empty()) {
                std::cout << "Stack is empty" << std::endl;
            }
            else {
                std::cout << "Minimum Element in the stack is: " << min_element << std::endl;
            }
        }

        // Prints top element:
        void peek() {
            if (true == s.empty()) {
                std::cout << "Stack is empty " << std::endl;
                return;
            }

            std::cout << "Top Element: ";
            if (int top = s.top(); top > min_element) {
                std::cout << top << std::endl;
            }
            else {
                std::cout << min_element << std::endl;
            }
        }

        // Removes the top element:
        void pop()
        {
            if (true == s.empty()) {
                std::cout << "Stack is empty " << std::endl;
                return;
            }

            std::cout << "Top Element Removed: ";
            int top = s.top();
            s.pop();

            // Minimum will change as the minimum element of the stack is being removed.
            if (min_element > top) {
                std::cout << min_element << std::endl;
                min_element = 2 * min_element - top;
            }
            else
                std::cout << top << std::endl;
        }

        // Removes top element from MyStack
        void push(int x) {
            // Insert new number into the stack
            if (true == s.empty()) {
                min_element = x;
                s.push(x);
                std::cout << "Number Inserted: " << x << std::endl;
                return;
            }

            // If new number is less than minEle
            if (min_element > x) {
                s.push(2 * x - min_element);
                min_element = x;
            }
            else {
                s.push(x);
            }

            std::cout << "Number Inserted: " << x << std::endl;
        }
    };
}

namespace
{

}

void StackAlgorithms::MinStack()
{
    MinStackImpl s;
    for (int i : {3, 4, 2, 1, 5, 6})
        s.push(i);

    s.getMin();
    s.pop();
    s.getMin();
    s.pop();
    s.getMin();
    s.pop();
    s.getMin();
}