/**============================================================================
Name        : Queue_Using_Stacks.cpp
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
        std::stack<T> mainStack;
        std::stack<T> stackReversed;

    public:
        Queue() = default;

        void put(T v) {
            mainStack.push(v);
        }

        T get()
        {
            if (stackReversed.empty() && mainStack.empty())
                throw std::runtime_error("We are empty;");

            if (stackReversed.empty()) {
                while (false == mainStack.empty()) {
                    stackReversed.push(mainStack.top());
                    mainStack.pop();
                }
            }

            T result = stackReversed.top();
            stackReversed.pop();
            return result;
        }

        [[nodiscard]]
        bool empty() const noexcept
        {
            return mainStack.empty() && stackReversed.empty();
        }
    };

    [[maybe_unused]]
    void Test()
    {
        Queue<int> queue;
        for (int i : {1, 2, 3, 4, 5})
            queue.put(i);

        while (false == queue.empty()) {
            std::cout << queue.get() << std::endl;
        }
    }

    [[maybe_unused]]
    void Test1()
    {
        Queue<int> queue;

        for (int i : {1, 2, 3, 4, 5, 6, 7, 8, 9})
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

void QueuesAlgorithms::Queue_Using_Stacks()
{
    // Test();
    Test1();
}