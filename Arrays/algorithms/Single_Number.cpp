/**============================================================================
Name        : Single_Number.cpp
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
    int single_number(const std::vector<int>& nums)
    {
        int singleNum = 0;
        for (const int num : nums) {
            singleNum ^= num;
        }
        return singleNum;
    }
}

void ArraysAlgorithms::Single_Number()
{
    for (const std::pair<std::vector<int>, int>& data:  std::vector<std::pair<std::vector<int>, int>>{
            {{2, 2, 1}, 1}, {{4,1,2,1,2}, 4}, {{1}, 1}
    })
    {
        std::cout << single_number(data.first) << std::endl;
    }
}