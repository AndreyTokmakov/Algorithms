/**============================================================================
Name        : Stack_Using_Two_Queues.cpp
Created on  : 11.02.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../StackAlgorithms.h"

#include <queue>

namespace {
    using namespace StackAlgorithms;

    template<typename T>
    class Stack {
        std::queue<T> queue;
        std::queue<T> tmp;

    public:
        Stack() = default;

        void put(T v) {
            queue.push(v);
        }

        T get() {
            if (queue.empty())
                throw std::runtime_error("We are empty;");

            while (1 != queue.size()) {
                tmp.push(queue.front());
                queue.pop();
            }

            T result = queue.front();
            queue.pop();
            queue.swap(tmp);

            return result;
        }

        bool empty() {
            return queue.empty();
        }
    };

}

namespace
{
    void Test()
    {
        Stack<int> queue_stack;

        for (int i: {1, 2, 3, 4, 5})
            queue_stack.put(i);

        while (false == queue_stack.empty()) {
            std::cout << queue_stack.get() << std::endl;
        }

    }

    void Test1()
    {
        Stack<int> stack;

        for (int i : {1, 2, 3, 4, 5, 6, 7, 8, 9})
            stack.put(i);

        int i = 5;
        while (i--)
            std::cout << stack.get() << std::endl;

        std::cout << std::endl;
        for (int i : {11, 12, 13, 14, 15})
            stack.put(i);

        while (false == stack.empty()) {
            std::cout << stack.get() << std::endl;
        }
    }
}

void StackAlgorithms::Stack_Using_Two_Queues()
{
    Test();
    Test1();
}