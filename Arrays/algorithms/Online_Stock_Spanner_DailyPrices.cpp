/**============================================================================
Name        : Online_Stock_Spanner_DailyPrices.cpp
Created on  : 19.03.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../ArraysAlgorithms.h"

/**
Design an algorithm that collects daily price quotes for some stock and returns the span of that stock's price for the current day.
The span of the stock's price in one day is the maximum number of consecutive days (starting from that day and going backward)
for which the stock price was less than or equal to the price of that day.

For example, if the prices of the stock in the last four days is [7,2,1,2] and the price of the stock today is 2,
then the span of today is 4 because starting from today, the price of the stock was less than or equal 2 for 4 consecutive days.
Also, if the prices of the stock in the last four days is [7,34,1,2] and the price of the stock today is 8, then
the span of today is 3 because starting from today, the price of the stock was less than or equal 8 for 3 consecutive days.

Implement the StockSpanner class:

StockSpanner() Initializes the object of the class.
int next(int price) Returns the span of the stock's price given that today's price is price.


Example 1: ["StockSpanner", "next", "next", "next", "next", "next", "next", "next"]
           [[], [100], [80], [60], [70], [60], [75], [85]]

        Output  [null, 1, 1, 1, 2, 1, 4, 6]

Explanation
            StockSpanner stockSpanner = new StockSpanner();
            stockSpanner.next(100); // return 1
            stockSpanner.next(80);  // return 1
            stockSpanner.next(60);  // return 1
            stockSpanner.next(70);  // return 2
            stockSpanner.next(60);  // return 1
            stockSpanner.next(75);  // return 4, because the last 4 prices (including today's price of 75)
                                    were less than or equal to today's price.
            stockSpanner.next(85);  // return 6
*/

namespace
{
    using namespace ArraysAlgorithms;

    struct StockSpanner
    {
        struct PriceSpan
        {
            int price { 0 };
            int span { 0 };
        };

        std::vector<PriceSpan> stock {};

        int next(const int price)
        {
            int span { 1 };
            while (!stock.empty() && stock.back().price <= price) {
                span += stock.back().span;
                stock.pop_back();
            }

            stock.emplace_back(price, span);
            return span;
        }
    };

}

void ArraysAlgorithms::Online_Stock_Spanner_DailyPrices()
{
    using TestData = std::vector<std::pair<std::vector<int>, std::vector<int>>>;
    for (const auto& [values, expected]:  TestData {
            { {100, 80, 60, 70, 60, 75, 85} , {1, 1, 1, 2, 1, 4, 6} },
    })
    {
        std::vector<int> actualOutput;
        StockSpanner stockSpanner {};
        std::for_each(values.begin(), values.end(), [&] (const int price) {
            actualOutput.push_back(stockSpanner.next(price));
        });

        if (expected != actualOutput) {
            std::cerr << std::boolalpha << expected << " != " << actualOutput << std::endl;
        }
    }
    std::cout << "OK: All tests passed\n";
}