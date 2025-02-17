/**============================================================================
Name        : Coins_Change_Problem.cpp
Created on  : 16.01.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../ArraysAlgorithms.h"

#include <numeric>


namespace
{
    using namespace ArraysAlgorithms;
    bool coins_change_problem(std::vector<int> coins,
                              const int target)
    {
        if (coins.empty())
            return false;
        std::cout <<"IN: " << coins << std::endl;

        if (const auto sum = std::accumulate(coins.begin(), coins.end(), 0); sum == target) {
            std::cout << sum << ": " << coins << std::endl;
            return true;
        }
        for (size_t i = 0; i < coins.size(); ++i) {
            std::vector<int> tmp(coins);
            tmp.erase(tmp.begin() + i);
            if (true == coins_change_problem(tmp, target))
                return true;
        }
        return false;
    }



}

void ArraysAlgorithms::Coins_Change_Problem()
{
    const std::vector<int> coins{1, 1, 1, 44, 1, 1, 36, 1, 1};
    constexpr int target = 82;

    const bool result = coins_change_problem(coins, target);
    std::cout << std::boolalpha << result << std::endl;
}
