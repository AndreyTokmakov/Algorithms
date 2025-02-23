/**============================================================================
Name        : Smallest_Subarray_With_Sum_Greater_Than_K.cpp
Created on  : 22.01.2025
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

    int smallest_subarray_with_sum_greater_brute_force(const std::vector<int>& values,
                                                          const int K)
    {
        int min_len = values.size();
        for (int i = 0, size = values.size(); i < size; i++)
        {
            for (int n = i, sum = 0; n < size; n++)
            {
                if (values[n] == K)
                    return 1;
                sum += values[n];
                if (sum > K)
                {
                    min_len = std::min(min_len, n - i + 1);

                    break;
                }
            }
        }
        return min_len;
    }

    size_t smallest_subarray_with_sum_greater_X_2(const std::vector<int>& values,
                                                  const int K)
    {
        int min_len = 0, sum = 0;

        // Get first 'minimum length' and 'sum' > X
        for (size_t i = 0; i < values.size() && sum <= K; i++) {
            sum += values[i];
            ++min_len;
        }

        // Next we will use 'sliding window' approach to check each window of length == 'minimum length' for its sum
        // and if sum of elements if 'window - last element' still > X that we can decrement 'minimum length' value.
        size_t end_pos = 0;
        for (size_t i = 1; i <= (values.size() - min_len) && min_len > 1; i++) {
            end_pos = min_len + i - 1;
            sum += values[end_pos] - values[i - 1];

            while ((sum - values[end_pos]) > K) {
                sum -= values[end_pos--];
                min_len--;
            }
        }
        return min_len;
    }

    size_t smallest_subarray_with_sum_greater_X_3(const std::vector<int>& values,
                                                  const int K)
    {
        size_t min_len = 0, sum = 0;
        // Get first 'minimum length' and 'sum' > X
        for (size_t i = 0; i < values.size() && sum <= K; i++) {
            sum += values[i];
            ++min_len;
        }

        // Next we will use 'sliding window' approach to check each window of length == 'minimum length' for its sum and
        // if sum of elements if 'window - last element' still > X that we can decrement 'minimum length' value.
        for (size_t i = min_len; i < values.size() && min_len > 1; i++)
        {
            sum += values[i] - values[i - min_len];
            while ((sum - values[i]) > K) {
                sum -= values[i--];
                min_len--;
            }
        }
        return min_len;
    }

    size_t smallest_subarray_with_sum_greater_prefix_sum(const std::vector<int>& values,
                                                         const int K)
    {
        const int size = values.size();

        // Compute the prefix sums
        std::vector<int> preSum(size + 1, 0);
        for (int i = 1; i <= size; i++)
            preSum[i] = preSum[i - 1] + values[i - 1];

        int res = std::numeric_limits<int>::max();
        for (int i = 1; i <= size; i++)
        {
            // Target sum for current subarray
            int toFind = K + preSum[i - 1];
            // Find the first prefix sum > target
            auto bound = std::lower_bound(preSum.begin(), preSum.end(), toFind);

            if (bound != preSum.end() && *bound != toFind) {
                int len = bound - (preSum.begin() + i - 1);
                res = std::min(res, len);
            }
        }

        // If subarray does not exist
        if (res == std::numeric_limits<int>::max())
            return 0;
        return res;
    }

    size_t smallest_subarray_with_sum_greater_prefix_sum_2(const std::vector<int>& values,
                                                           const int K)
    {
        const int size = values.size();

        // Compute the prefix sums
        std::vector<int> preSum(size, values.front());
        for (int i = 1, sum = values.front(); i < size; i++)
            preSum[i] = (sum += values[i]);

        int res = std::numeric_limits<int>::max();
        for (int i = 0; i <= size; i++)
        {
            // Target sum for current subarray
            int toFind = K + preSum[i];
            // Find the first prefix sum > target
            auto bound = std::lower_bound(preSum.begin(), preSum.end(), toFind);

            if (bound != preSum.end() && *bound != toFind) {
                int len = bound - (preSum.begin() + i);
                res = std::min(res, len);
            }
        }

        // If subarray does not exist
        if (res == std::numeric_limits<int>::max())
            return 0;
        return res;
    }

    int smallest_subarray_with_sum_greater__two_pointers(const std::vector<int>& values,
                                                         const int K)
    {
        int ans = std::numeric_limits<int>::max();
        for (int idx = 0, size = values.size(), i = 0, sum = 0; idx < size; )
        {
            // Expand window until sum > x or end of array reached
            while (idx < size && sum <= K) {
                sum += values[idx++];
            }

            // If we reached end of array and sum still <= x, no valid subarray exists
            if (idx == size && sum <= K)
                break;

            // Minimize window from start while maintaining sum > x
            while (i < idx && sum - values[i] > K) {
                sum -= values[i++];
            }

            ans = std::min(ans, idx - i);

            // Remove current start element and shift window
            sum -= values[i];
            i++;
        }

        // Return 0 if no valid subarray found, else return min length
        return ans == std::numeric_limits<int>::max() ? 0 : ans;
    }
}

void ArraysAlgorithms::Smallest_Subarray_With_Sum_Greater_Than_K()
{
    // const std::vector<int> values { 3, 4, 4, 1, 9, 6, 1, 3, 9, 5, 1, 3, 9, 10, 10, 4, 8, 3, 6, 8, 4, 2, 5, 8, 9 };
    // const int K = 24;

    const std::vector<int> values { 2,3,1,2,4,3 };// -> 2
    const int K = 7;

    // [1,4,4] 1 ---> 2
    // [1,1,1,1,1,1,1,1] 11 ---> 0

    std::cout << smallest_subarray_with_sum_greater_brute_force(values, K) << std::endl;
    std::cout << smallest_subarray_with_sum_greater_X_2(values, K) << std::endl;
    std::cout << smallest_subarray_with_sum_greater_X_3(values, K) << std::endl;
    std::cout << smallest_subarray_with_sum_greater_prefix_sum(values, K) << std::endl;
    std::cout << smallest_subarray_with_sum_greater_prefix_sum_2(values, K) << std::endl;
    std::cout << smallest_subarray_with_sum_greater__two_pointers(values, K) << std::endl;
}