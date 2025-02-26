/**============================================================================
Name        : Add_Digits.cpp
Created on  : 10.02.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../ArraysAlgorithms.h"


/**
   You are given an array prices where prices[i] is the price of a given stock on the ith day.
   You want to maximize your profit by choosing a single day to buy one stock and choosing a
   different day in the future to sell that stock.
   Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

   Example 1: Input: prices = [7,1,5,3,6,4]  Output: 5
       Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
       Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

   Example 2: Input: prices = [7,6,4,3,1] Output: 0
       Explanation: In this case, no transactions are done and the max profit = 0.
   */

namespace
{
    int best_time_buy_and_sell_stock(const std::vector<int>& prices)
    {
        int profit = 0;
        for (int bidPrice = prices[0]; const int currPrice : prices) {
            profit = std::max(profit, currPrice - bidPrice);
            bidPrice = std::min(bidPrice, currPrice);
        }
        return profit;
    }
}

void ArraysAlgorithms::Best_Time_Buy_and_Sell_Stock()
{
    for (const std::pair<std::vector<int>, int>& data: std::vector<std::pair<std::vector<int>, int>>{
            {{7,1,5,3,6,4}, 5},
            {{7,6,4,3,1}, 0},
            {{7,8,1,5,3,6,4}, 5},
    }) {
        if (const auto actual = best_time_buy_and_sell_stock(data.first); actual != data.second)
        {
            std::cout << "Expected value is " << data.second << ", Actual: " << actual << std::endl;
        }
    }
    std::cout << "OK: All tests passed\n";
}