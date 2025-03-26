/**============================================================================
Name        : Is_Array_Consecutive.cpp
Created on  : 23.03.2025
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

    bool is_array_consecutive_1(const std::vector<int> &values)
    {
        std::unordered_set<int> map;
        int minElement = std::numeric_limits<int>::max(), maxElement = std::numeric_limits<int>::min();
        for (const int val: values) {
            minElement = std::min(minElement, val);
            maxElement = std::max(maxElement, val);
            if (!map.emplace(val).second)
                return false;
        }
        while (minElement != maxElement) {
            if (!map.contains(++minElement))
                return false;
        }
        return true;
    }

    bool is_array_consecutive_2(const std::vector<int> &values)
    {
        std::set<int> tmp(values.begin(), values.end());
        for (int minVal = *tmp.begin() + 1, maxVal = *std::prev(tmp.end()); minVal < maxVal; ++minVal) {
            if (!tmp.contains(minVal))
                return false;
        }
        return true;
    }

    /** Using Visited Array:
     *
     * The idea is to check if all elements in the array can form a consecutive sequence by first finding the minimum
     * and maximum values in the array, then verifying two key conditions:
     *
     * the range (max-min+1) should equal the array length, indicating no gaps in the sequence
     * Each number in the range should appear exactly once, which is validated using a visited array where
     * each element’s position is marked relative to the minimum value.
    */
    bool is_array_consecutive_visited(const std::vector<int> &values)
    {
        const int size = static_cast<int>(values.size());
        int minElement = std::numeric_limits<int>::max(), maxElement = std::numeric_limits<int>::min();
        for (const int val: values) {
            minElement = std::min(minElement, val);
            maxElement = std::max(maxElement, val);
        }

        // If elements are consecutive, then there should be maxi-mini+1 elements.
        if (maxElement - minElement + 1 != size)
            return false;

        std::vector<bool> tblVisited(size, false);
        for (const int val: values)
        {
            if (tblVisited[val - minElement]) {  /** If element is already marked **/
                return false;
            }
            tblVisited[val - minElement] = true; /** Mark the element. **/
        }

        return true;
    }

    /**  Using Negative Marking
     *
     * The idea is to use the original array itself for marking visited elements.
     *
     * This approach still checks for the necessary conditions of a consecutive sequence by finding the min-max range,
     * but instead of creating an auxiliary visited array, it marks each visited position by negating the
     * value at the corresponding index (calculated as value-min)
     *
     * If any element is already negative when we attempt  to mark it, it indicates a duplicate,
     * thus failing the consecutive number requirement.
     *
     * NOTE: Will fail in case {-3,-2,-1,0,1,2,3}
     *       Where we have elements in range with same ABSolute value
    **/
    bool is_array_consecutive_Negative(std::vector<int> &values)
    {
        const int size = static_cast<int>(values.size());
        int minElement = std::numeric_limits<int>::max(), maxElement = std::numeric_limits<int>::min();
        for (const int val: values) {
            minElement = std::min(minElement, val);
            maxElement = std::max(maxElement, val);
        }

        // If elements are consecutive, then there should be maxi-mini+1 elements.
        if (maxElement - minElement + 1 != size)
            return false;

        for (int idx = 0; idx < size; ++idx)
        {
            int val = abs(values[idx]);

            // If value is already marked as negative, return false as it is already present.
            if (values[val - std::abs(minElement)] < 0) {
                return false;
            }
            // Mark the value
            values[val - minElement] *= -1;
        }

        return true;
    }

    /**  Using XOR
     *
     * The idea is to use the XOR operation’s property where XOR of a number with itself results in 0.
     * After verifying that the array’s range is valid (max-min+1 equals array length), the approach takes the XOR of
     * all numbers in the expected range [min, max] and then XORs this result with all actual elements in the array.
     *
     * If the array contains exactly the consecutive numbers in the expected range, each number will appear exactly twice
     * in the XOR operation (once from the range and once from the array), resulting in all values canceling out to produce
     * a final XOR value of 0, confirming that the array consists of consecutive numbers.
    **/
    bool is_array_consecutive_XOR(const std::vector<int> &values)
    {
        const int size = static_cast<int>(values.size());
        int minElement = std::numeric_limits<int>::max(), maxElement = std::numeric_limits<int>::min();
        for (const int val: values) {
            minElement = std::min(minElement, val);
            maxElement = std::max(maxElement, val);
        }

        // If elements are consecutive, then there should be maxi-mini+1 elements.
        if (maxElement - minElement + 1 != size)
            return false;

        int xorVal = 0;
        for (int val = minElement; val <= maxElement; ++val) {
            xorVal ^= val;
        }

        // Take xor of all values present in the array
        for (const int val: values) {
            xorVal ^= val;
        }
        return xorVal == 0;
    }


    bool sort_based_approach(std::vector<int> values)
    {
        int minElement = *std::min_element(values.begin(), values.end());
        for (int& val: values) {
            std::swap(val, values[val - minElement]);
        }

        std::cout << values << std::endl;

        for (const int val: values) {
            if (val != minElement++)
                return false;
        }
        return true;
    }
}

void ArraysAlgorithms::Is_Array_Consecutive()
{
    using TestData = std::vector<std::pair<std::vector<int>, bool>>;
    for (int testNum = 1; const auto& [values, expected]:  TestData {
            { {1,2,3} , true },
            { {-1,-2,-3,-4,-4,-6} , false },
            { {1,2, 4} , false },
           { {1,3,3,3,5} , false },
            { {5,4,1,3, 2} , true },
            {  {-3,-2,-1,0,1,2,3} , true },
            { {3,2,1,0,-1,-2,-3} , true },
           { {6,9,3,1,5,4,7,8,2} , true },
    })
    {
        /*
        if (const auto actual = is_array_consecutive_1(values); expected != actual) {
            std::cerr << "Test-1 number #" << testNum  << " failed: " <<  expected << " != " << actual << std::endl;
        }
        if (const auto actual = is_array_consecutive_2(values); expected != actual) {
            std::cerr << "Test-2 number #" << testNum  << " failed: " <<  expected << " != " << actual << std::endl;
        }
        if (const auto actual = is_array_consecutive_visited(values); expected != actual) {
            std::cerr << "Test-3 number #" << testNum  << " failed: " <<  expected << " != " << actual << std::endl;
        }
        if (const auto actual = is_array_consecutive_XOR(values); expected != actual) {
            std::cerr << "Test-5 number #" << testNum  << " failed: " <<  expected << " != " << actual << std::endl;
        }*/

        /*
        std::vector<int> vals { values };
        if (const auto actual = is_array_consecutive_Negative(vals); expected != actual) {
            std::cerr << "Test-4 number #" << testNum  << " failed: " <<  expected << " != " << actual << std::endl;
        }*/


        if (const auto actual = sort_based_approach(values); expected != actual) {
            std::cerr << "Test-6 number #" << testNum  << " failed: " <<  expected << " != " << actual << std::endl;
        }

        ++testNum;
    }
    std::cout << "OK: All tests passed\n";
}