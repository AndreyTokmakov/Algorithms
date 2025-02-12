/**============================================================================
Name        : Queue_Using_Stacks_Recursive.cpp
Created on  : 11.02.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../QueuesAlgorithms.h"

namespace
{
    using namespace QueuesAlgorithms;

    template<typename T>
    class Queue
    {
        std::stack<T> stack;

    public:
        Queue() = default;

        void put(T v) {
            stack.push(v);
        }

        T get() {
            if (stack.empty())
                throw std::runtime_error("We are empty;");

            T x = stack.top();
            stack.pop();
            if (stack.empty())
                return x;

            // recursive call
            T item = get();

            stack.push(x);
            return item;
        }

        [[nodiscard]]
        bool empty() const noexcept {
            return stack.empty();
        }
    };

    [[maybe_unused]]
    void Test()
    {
        Queue<int> queue;
        for (const int i : {1, 2, 3, 4, 5})
            queue.put(i);
        while (false == queue.empty()) {
            std::cout << queue.get() << std::endl;
        }
    }

    [[maybe_unused]]
    void Test1()
    {
        Queue<int> queue;
        for (const int i : {1, 2, 3, 4, 5, 6, 7, 8, 9})
            queue.put(i);

        int i = 5;
        while (i--)
            std::cout << queue.get() << std::endl;

        std::cout << std::endl;
        for (int i : {11, 12, 13, 14, 15})
            queue.put(i);

        while (false == queue.empty()) {
            std::cout << queue.get() << std::endl;
        }
    }
}

void QueuesAlgorithms::Queue_Using_Stacks_Recursive()
{
    // Test();
    Test1();
}