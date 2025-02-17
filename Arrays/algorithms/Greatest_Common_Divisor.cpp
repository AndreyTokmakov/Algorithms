/**============================================================================
Name        : Greatest_Common_Divisor.cpp
Created on  : 16.01.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../ArraysAlgorithms.h"


namespace
{
    using namespace ArraysAlgorithms;

    int gsd_recur_1(const int a, const int b) {
        return 0 == b ? a : gsd_recur_1(b, a % b);
    }

    template<typename Type>
    std::enable_if_t<std::is_integral_v<Type>, Type> gsd_recur_2(Type a, Type b) {
        return 0 == b ? a : gsd_recur_2(b, a % b);
    }

    int gsd_loop_1(int a, int b)
    {
        while (b != 0) {
            a = a % b;
            std::swap(a, b);
        }
        return a;
    }

    int gsd_loop_2(int a, int b)
    {
        while (true)
        {
            if (a == 0)
                return b;
            b %= a;
            if (b == 0)
                return a;
            a %= b;
        }
    }
}

void ArraysAlgorithms::Greatest_Common_Divisor()
{
    for (const auto& [values, expected]: std::vector<std::pair<IntPair, int>>{
            {{8, 3}, 1},
            {{27, 18}, 9},
            {{128, 40}, 8},
    }) {
        std::cout
                << gsd_recur_1(values.first, values.second) << " | "
                << gsd_recur_2(values.first, values.second) << " | "
                << gsd_loop_1(values.first, values.second) << " | "
                << gsd_loop_2(values.first, values.second) << " | "
                << " Expected: " << expected << std::endl;
    }
}