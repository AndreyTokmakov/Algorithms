/**============================================================================
Name        : other.cpp
Created on  : 10.02.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../ArraysAlgorithms.h"

#include <random>
#include <cassert>
#include <queue>
#include <ranges>

namespace
{
    void FillVecor(std::vector<int> &vecor,
                   unsigned int size,
                   unsigned int range_start = 0,
                   unsigned int range_end = 10000) {
        std::random_device random_device;
        std::mt19937 generator(random_device());
        std::uniform_int_distribution<> distribution(range_start, range_end);
        for (unsigned int i = 0; i < size; i++)
            vecor.push_back(distribution(generator));
    }

    using namespace ArraysAlgorithms;
}


namespace Numeric
{
    bool __isPowerOf2(int num) {
        return num && !(num & (num - 1));
    }

    void isPowerOf2() {
        for (const int32_t value: {8, 64, 61}) {
            std::cout << value << " -> " << std::boolalpha << __isPowerOf2(value) << std::endl;
        }
    }
}



namespace Numeric
{
    int gsd_recur_1(int a, int b) {
        return 0 == b ? a : gsd_recur_1(b, a % b);
    }

    template<typename Type>
    std::enable_if_t<std::is_integral_v<Type>, Type> gsd_recur_2(Type a, Type b) {
        return 0 == b ? a : gsd_recur_2(b, a % b);
    }

    int gsd_loop_1(int a, int b) {
        while (b != 0) {
            a = a % b;
            std::swap(a, b);
        }
        return a;
    }

    int gsd_loop_2(int a, int b) {
        while (true) {
            if (a == 0)
                return b;
            b %= a;
            if (b == 0)
                return a;
            a %= b;
        }
    }

    void GreatestCommonDivisor()
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
}

namespace Numeric
{
    int __gcd__(int a, int b) {
        while (b != 0) {
            a = a % b;
            std::swap(a, b);
        }
        return a;
    }

    int __lcm__(int a, int b) {
        int gcd = __gcd__(a, b);
        return gcd ? (a * b / gcd) : 0;
    }

    void LeastCommonMultiple() {

        int a = 128, b = 40;
        std::cout << __lcm__(a, b) << std::endl;
    }

    //---------------------------------------------------------------------------//

    /* Returns length of LCS for X[0..m-1], Y[0..n-1] */
    int lcs(const char *X, const char *Y, int m, int n) {
        if (m == 0 || n == 0)
            return 0;
        if (X[m - 1] == Y[n - 1])
            return 1 + lcs(X, Y, m - 1, n - 1);
        else
            return std::max(lcs(X, Y, m, n - 1), lcs(X, Y, m - 1, n));
    }


    void LongestCommonSubsequence() {

        const std::string X = "AGGTAB", Y = "GXTXAYB"; // ---> GTAB

        std::cout << "Length of LCS is " << lcs(X.c_str(), Y.c_str(), X.length(), Y.length());
    }


    //---------------------------------------------------------------------------//

    void FinabochiNumeric() {
        int a = 0, b = 1, max = 100000;
        std::cout << a << " " << b << " ";

        while (b < max) {
            int c = a + b;
            a = b;
            b = c;
            std::cout << b << " ";
        }
    }

    //---------------------------------------------------------------------------//

    void CountAndSaySequence_Generate() {
        std::vector<std::string> sequence = {"1"};
        int K = 10;

        for (int i = 0; i < K - 1; i++) {
            std::vector<std::pair<char, int>> tokens;
            for (char c: sequence.back()) {
                if (false == tokens.empty() && tokens.back().first == c)
                    tokens.back().second++;
                else
                    tokens.push_back({c, 1});
            }

            std::string result;
            for (const auto &p: tokens) {
                result.append(std::to_string(p.second));
                result.append(1, p.first);
            }
            sequence.push_back(result);
        }

        for (const std::string &str: sequence)
            std::cout << str << std::endl;
    }

    //---------------------------------------------------------------------------//

    std::string CountAndSaySequence_Get_Kth_Token(int K) {
        if (1 == K)
            return "1";

        std::string token("1");
        while (--K) {
            std::vector<std::pair<char, int>> tokens;
            for (char c: token) {
                if (false == tokens.empty() && tokens.back().first == c)
                    tokens.back().second++;
                else
                    tokens.push_back({c, 1});
            }

            token.clear();
            for (const auto &p: tokens) {
                token.append(std::to_string(p.second));
                token.append(1, p.first);
            }
        }
        return token;
    }


    std::string CountAndSaySequence_Get_Kth_Token_2(int K) {
        if (1 == K)
            return "1";

        std::string token("1"), temp;
        while (--K) {
            std::pair<char, size_t> chars{token.front(), 1};
            for (size_t i = 1; i < token.length(); ++i) {
                if (chars.first == token[i])
                    chars.second++;
                else {
                    temp.append(std::to_string(chars.second));
                    temp.append(1, chars.first);
                    chars = {token[i], 1};
                }
            }

            temp.append(std::to_string(chars.second));
            temp.append(1, chars.first);

            token.assign(temp);
            temp.clear();
        }
        return token;
    }

    std::string CountAndSaySequence_Get_Kth_Token_3(int K) {
        if (1 == K)
            return "1";

        std::string token("1"), temp;
        while (--K) {
            char c{token.front()};
            size_t repetions{1};
            for (size_t i = 1; i < token.length(); ++i) {
                if (c == token[i])
                    ++repetions;
                else {
                    temp.append(std::to_string(repetions));
                    temp.append(1, c);
                    c = token[i];
                    repetions = 1;
                }
            }

            temp.append(std::to_string(repetions));
            temp.append(1, c);
            token.assign(temp);
            temp.clear();
        }
        return token;
    }

    void CountAndSaySequence_Get_Kth_Token() {
        {
            std::string token = CountAndSaySequence_Get_Kth_Token(7);
            // assert("13112221" == token);
            std::cout << token << std::endl;
        }
        {
            std::string token = CountAndSaySequence_Get_Kth_Token_2(7);
            std::cout << token << std::endl;
        }
        {
            std::string token = CountAndSaySequence_Get_Kth_Token_3(7);
            std::cout << token << std::endl;
        }
    }

    //---------------------------------------------------------------------------//

    void _find_finabochi_subset(const std::vector<int> &Numeric) {
        int max = *std::max_element(Numeric.begin(), Numeric.end());
        int a = 0, b = 1, c = a + b;
        std::vector<int> finabochiNumeric{a, b};

        while (b < max) {
            c = a + b;
            a = b;
            b = c;
            finabochiNumeric.push_back(b);
        }

        size_t offset = 0, max_len = 0, curr_len = 0;
        std::vector<int>::const_iterator iter = Numeric.begin();
        while (Numeric.size() >= (max_len + offset)) {
            iter = std::mismatch(Numeric.begin() + offset, Numeric.end(), finabochiNumeric.begin(), finabochiNumeric.end()).first;
            curr_len = std::max(int(std::distance(Numeric.begin() + offset, iter)), 1);
            max_len = std::max(max_len, curr_len);
            offset += curr_len;
        }
        std::cout << max_len << std::endl;
    }

    void _find_finabochi_subset_2(const std::vector<int> &Numeric) {
        size_t max_len = 0, len = 0;
        for (size_t pos = 2; pos < Numeric.size(); ++pos) {
            if ((Numeric[pos - 2] + Numeric[pos - 1]) == Numeric[pos]) {
                len = (0 == len) ? 3 : len + 1;
                max_len = std::max(max_len, len);
            } else {
                len = 0;
            }
        }
        std::cout << max_len << std::endl;
    }

    void LongestSubset_FinabochiNumeric() {
        {
            // MAX 22
            std::vector<int> v{0, 1, 1, 2, 3, 5, 8, 0, 1, 1, 2, 3, 5, 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 8,
                               8, 8, 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765,
                               10946};
            _find_finabochi_subset(v);
            _find_finabochi_subset_2(v);
        }
        std::cout << "\nTEST2:\n" << std::endl;
        {
            // MAX 16
            std::vector<int> v{3, 34, 0, 1, 1, 2, 3, 5, 8, 13, 3, 1343, 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 3, 2, 345, 89, 144, 233,
                               377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393};
            _find_finabochi_subset(v);
            _find_finabochi_subset_2(v);
        }
    }

    //---------------------------------------------------------------------------//

    int _get_num_of_digits(int val) {
        return val > 10 ? 1 + _get_num_of_digits(val / 10) : 1;
    }

    int _get_num_of_digits2(int val) {
        int digits{1};
        while (val > 9) {
            val = val / 10;
            ++digits;
        }
        return digits;
    }

    void GetNumberOfDigit() {
        int val = 123432323;
        std::cout << val << " = " << _get_num_of_digits(val) << std::endl;
        std::cout << val << " = " << _get_num_of_digits2(val) << std::endl;
    }
}

namespace Numeric
{
    int reverse_number(int number)
    {
        int reversed = 0;
        while (0 != number) {
            reversed = reversed * 10 + number % 10;
            number = number / 10;
        }
        return reversed;
    }

    void ReverseNumber()
    {
        for (const auto& [value, expected]: std::vector<IntPair> {
                {123, 321}, {210, 12}, { -173, -371},
                {1234567, 7654321},
                {-4030, -304},
        }) {
            if (const auto actual = reverse_number(value); expected != actual) {
                std::cerr << expected << " != " << actual << std::endl;
                return;
            }
        }
        std::cout << "OK: All tests passed\n";
    }
}

namespace Numeric
{
    bool is_palindrome(const int value)
    {
        if (0 > value)
            return false;
        long reversed = 0, number = value;
        while (0 != number) {
            reversed = reversed * 10 + number % 10;
            number = number / 10;
        }
        return reversed == value;
    }

    void IsPalindrome() {
        for (const int v: std::vector<int>{
                121, 234
        }) {
            std::cout << "Is (" << v << ") palidrome: " << std::boolalpha << is_palindrome(v) << std::endl;
        }
    }

    //---------------------------------------------------------------------------//

    // Move items to their places
    void RearangeArray() {
        int Numeric[] = {8, 7, 6, 3, 4, 9, 2, 1, 0, 5};
        size_t length = std::size(Numeric);

        for (int v: Numeric)
            std::cout << v;
        std::cout << std::endl;

        for (int i = 0; i < static_cast<int>(length); i++) {
            if (Numeric[i] != i)
                std::swap(Numeric[Numeric[i]], Numeric[i]);
        }

        for (unsigned int v: Numeric)
            std::cout << v;
        std::cout << std::endl;
    }

    //---------------------------------------------------------------------------//

    int test1(int a, int b) {
        int count = 0;
        while (a >= b) {
            a -= b;
            count++;
        }
        return count;
    }

    int test2(int a, int b) {
        int count = 0, result = b;
        while (a > result) {
            result += b;
            count++;
        }
        return count;
    }

    void Devide_WithDevisionOperator() {
        {
            int a = 15, b = 2;
            std::cout << a << "/" << b << " = " << test1(a, b) << std::endl;
            std::cout << a << "/" << b << " = " << test2(a, b) << std::endl;
        }
        {
            int a = 1511, b = 22;
            std::cout << a << "/" << b << " = " << test1(a, b) << std::endl;
            std::cout << a << "/" << b << " = " << test2(a, b) << std::endl;
        }
    }

    //---------------------------------------------------------------------------//


    // Print characters along the collection starting from the 0 - end with the specified offset: NULL should be ignored
    //  [1, 2, null, null, 3, 4, 5] -> [3, 4, 4, 4, 5, null, null]  with Offet = 2
    //  [0, 1, 2, null, null, 3, 4, 5] -> [2, 3, 4, 4, 4, 5, null, null] with Offet = 2
    void leadIgnoreNulls(const std::vector<std::optional<int>> &values,
                         const size_t offset) {
        const size_t size{values.size()};
        for (size_t i = 0; i < size; ++i) {
            if ((i + offset) >= size) {
                std::cout << "Null\n";
                continue;
            }

            size_t n = i + 1, steps = 0;
            while (size > n && offset >= steps) {
                if (!values[n].has_value()) {
                    n++;
                    continue;
                }

                if (offset == ++steps) {
                    std::cout << values[n].value() << std::endl;
                    break;
                }
                n++;
            }
        }
    }

    void LeadNumber_Window_IgnoreNulls() {
        //
        // const std::vector<std::optional<int>> values { 1,2, std::nullopt, std::nullopt,3 ,4 ,5 };

        // [0, 1, 2, null, null, 3, 4, 5] -> [2, 3, 4, 4, 4, 5, null, null]
        const std::vector<std::optional<int>> values{0, 1, 2, std::nullopt, std::nullopt, 3, 4, 5};

        // const std::vector<std::optional<int>> values { 1,2 ,std::nullopt, std::nullopt, 3};
        // const std::vector<std::optional<int>> values { 1,2,3 };

        leadIgnoreNulls(values, 2);
    }

    //---------------------------------------------------------------------------//

    double getAngleOnClock(std::string_view timeStr) {
        const size_t pos = timeStr.find(':');
        const double hours = atoi(timeStr.substr(0, pos).data());
        const double minutes = atoi(timeStr.substr(pos + 1, timeStr.length() - pos - 1).data());

        /*
         * The whole dial is 360 degrees and each interval is 30 degrees
         * Then there will be 150 degrees (5 intervals) between the marks corresponding to 10 and 15
         * However, the hour hand will shift from 10 to 15 minutes, which is 25% of the hour, that is 7.5 degrees from 30.
         * Then 150-7.5=142.5
         */

        auto degrees = std::abs(hours * 30 - minutes * 6 + (30 * minutes) / 60);
        degrees = std::min(degrees, 360 - degrees);

        [[maybe_unused]]
        const double radians = (degrees * std::numbers::pi) / 180;

        // std::cout << "degrees = " << degrees << std::endl;
        // std::cout << "radians = " << radians << std::endl;
        return degrees;
    }

    void AnalogClockAngles() {
        // std::string timeString = "03:00";
        std::string timeString = "09:30";

        getAngleOnClock(timeString);
    }

    //---------------------------------------------------------------------------//

    int _sqrt(int x) {
        int left = 0, right = x, middle = 0, result = 0;
        while (left <= right) {
            middle = (right + left) / 2;
            result = middle * middle;
            if (result == x)
                return middle;
            else if (result > x)
                right = middle - 1;
            else
                left = middle + 1;
        }
        return right;
    }

    void Sqrt() {
        int s = _sqrt(9);
        std::cout << s << std::endl;
    }

    //---------------------------------------------------------------------------//

    // Write a function that, given three integers A, B and K, returns the
    // number of integers within the range[A..B] that are divisible by K, i.e. :

    int __test1(int A, int B, int K) {
        int tmp = (0 == A % K) ? 1 : 0;
        return B / K - A / K + tmp;
    }

    int __test2(int A, int B, int K) {
        int count = (0 == A % K) ? 1 : 0, dev = (A / K) * K;
        while (B >= dev) {
            dev += K;
            count++;
        }
        return count - 1;
    }

    void ComputeNumberOfDivisiblsInRange() {
        int A = 8, B = 16, K = 4;
        std::cout << __test1(A, B, K) << std::endl;
        std::cout << __test2(A, B, K) << std::endl;
    }

    //----------------------------------------------------------------------------//

    void _count_ordered_pairs(int N) {
        for (int a = 1; a <= N; a++) {
            for (int b = 1; N > (a * b); b++) {
                std::cout << a << " " << b << std::endl;
            }
        }
    }

    // Given an integer N. The task is to count the number of ordered pairs (a, b) such that a * b < N.
    void CountOrderedPairs() {
        int N = 5;
        _count_ordered_pairs(N);
    }

    //----------------------------------------------------------------------------//

    std::vector<int> _largest_triple_products(const std::vector<int> &number) {
        std::vector<int> result;
        for (size_t i = 0; i < number.size(); i++) {
            if (1 >= i) {
                result.push_back(-1);
                continue;
            }

            std::vector<int> heap = {-1, -1, -1};
            std::make_heap(heap.begin(), heap.end(), [](int x, int y) { return y < x; });

            for (size_t n = 0; n <= i; n++) {
                if (number[n] >= heap[0]) {
                    heap[0] = number[n];
                    std::make_heap(heap.begin(), heap.end(), [](int x, int y) { return y < x; });
                }
            }
            int product = std::accumulate(heap.begin(), heap.end(), 1, [](int x, int y) { return x * y; });
            result.push_back(product);
        }
        return result;
    }

    // You're given a list of n integers arr[0..(n-1)]. You must compute a list output[0..(n-1)] such that,
    // for each index i (between 0 and n-1, inclusive), output[i] is equal to the product of the three largest
    // elements out of arr[0..i] (or equal to -1 if i < 2, as arr[0..i] then includes fewer than three elements).
    // Note that the three largest elements used to form any product may have the same values as one another,
    // but they must be at different indices in arr.
    // arr = [1, 2, 3, 4, 5] ---> output = [-1, -1, 6, 24, 60]
    void Largest_Triple_Products() {
        {
            std::vector<int> number = {1, 2, 3, 4, 5};
            std::vector<int> result = _largest_triple_products(number);
            for (int i: result)
                std::cout << i << " ";
            std::cout << std::endl;
        }
        {
            std::vector<int> number = {2, 1, 2, 1, 2};
            std::vector<int> result = _largest_triple_products(number);
            for (int i: result)
                std::cout << i << " ";
            std::cout << std::endl;
        }
    }

    //----------------------------------------------------------------------------//

    int getBillionUsersDay(std::vector<float> growthRates) {
        int count = 1;
        std::vector<float> results(growthRates);
        float sum = 0;

        while (1000000000 > sum) {
            for (size_t i = 0; i < growthRates.size(); i++) {
                results[i] *= growthRates[i];
            }

            sum = 0;
            std::for_each(results.begin(), results.end(), [&sum](float v) { sum += v; });
            count++;
        }
        return count;
    }

    // We have N different apps with different user growth rates. At a given time t, measured in days,
    // the number of users using an app is g^t (for simplicity we'll allow fractional users),
    // where g is the growth rate for that app. These apps will all be launched at the same time
    // and no user ever uses more than one of the apps. After how many full days will
    // have 1 billion total users across the N apps ?
    // growthRates = [1.5] -> Result: 52
    // growthRates = [1.1, 1.2, 1.3] -> Result: 79
    void BillionUsers() {
        std::vector<float> growthRates1 = {1.5};
        std::vector<float> growthRates2 = {1.1, 1.2, 1.3};
        std::vector<float> growthRates3 = {1.01, 1.02};

        std::cout << getBillionUsersDay(growthRates1) << std::endl;
        std::cout << getBillionUsersDay(growthRates2) << std::endl;
        std::cout << getBillionUsersDay(growthRates3) << std::endl;
    }

    //---------------------------------------------------------------------------//

    // Given an array of integers(which may include repeated integers), determine if there's a
    // way to split the array into two subarrays A and B such that the sum of the integers in both
    // arrays is the same, and all of the integers in A are strictly smaller than all of the integers in B.
    // Note: Strictly smaller denotes that every integer in A must be less than, and not equal to, every integer in B.
    void BalancedSplit() {
        std::vector<int> nums = {12, 7, 6, 7, 6};


        // int left = 0, right = nums.size() - 1;
        int leftSum = 0, rightSum = 0;

        // Sort
        std::sort(nums.begin(), nums.end());

        // Calc left half summ:
        for (size_t i = 0; i < nums.size() / 2; i++)
            leftSum += nums[i];

        // Calc right half summ:
        for (size_t i = nums.size() / 2; i < nums.size(); i++)
            rightSum += nums[i];

        size_t pos = nums.size() / 2;
        while (pos >= 0 && pos < nums.size()) {
            if (leftSum > rightSum) {
                leftSum -= nums[--pos];
                rightSum += nums[--pos];
            } else if (rightSum > leftSum) {
                rightSum -= nums[pos];
                leftSum += nums[pos++];
            } else {
                if (nums[pos - 1] < nums[pos])
                    std::cout << "OK" << std::endl;
                else
                    std::cout << "NO" << std::endl;
                break;
            }
        }
        std::cout << "NO" << std::endl;
    }

    //---------------------------------------------------------------------------//

    void Kadane()
    {
        {
            // Fill vector with maximum sums:
            std::vector<int> values = {1, -3, 2, 1, -1};
            std::vector<int> max_sums(values);
            for (size_t index = 1; index < max_sums.size(); index++)
                max_sums[index] = std::max(max_sums[index - 1] + values[index], values[index]);
            std::cout << max_sums << std::endl;
        }

        {
            const std::vector<int> numbers{1, -3, 2, 1, -1, 2};
            int max_before = numbers.front(), max = max_before;
            for (size_t index = 1; index < numbers.size(); index++) {
                max_before = std::max(max_before + numbers[index], numbers[index]);
                max = std::max(max, max_before);
            }
            std::cout << "max = " << max << std::endl;
        }
    }

    //---------------------------------------------------------------------------//

    int __max_sum_subarray(const std::vector<int> &Numeric) {
        int max_before = Numeric.front(), max = max_before;
        for (size_t index = 1; index < Numeric.size(); index++) {
            max_before = std::max(max_before + Numeric[index], Numeric[index]);
            max = std::max(max, max_before);
        }
        return max;
    }

    void MaximumSumSubarray_Kadane() {
        {
            std::vector<int> Numeric = {1, -3, 2, 1, -1};
            int X = __max_sum_subarray(Numeric);
            assert(3 == X);
            std::cout << "Max sum subarray for [" << Numeric << "] is = " << X << std::endl;
        }
        {
            std::vector<int> Numeric = {-1, 4, -2, 5, -5, 2, -20, 6};
            int X = __max_sum_subarray(Numeric);
            assert(7 == X);
            std::cout << "Max sum subarray for [" << Numeric << "] is = " << X << std::endl;
        }
    }

    //---------------------------------------------------------------------------//

//---------------------------------------------------------------------------//
    void printArray(const std::vector<int> &vect, size_t start, size_t end) {
        std::cout << "[ ";
        while (end >= start)
            std::cout << vect[start++] << " ";
        std::cout << "]" << std::endl;
    }

    void printAllSubArrays(const std::vector<int> &vect) {
        for (size_t size = vect.size(), i = 0; i < size; ++i) {
            for (size_t n = i; n < size; ++n)
                printArray(vect, i, n);
        }
    }

    void GetAllSubsequentSubArrays() {
        printAllSubArrays({1, 2, 3, 4});
    }

    // ----------------------------------------------------------------------//
    void printAllSubArrays_NonSequenced(const std::vector<int> &vect) {
        //total number of possible non-empty sub-sequences
        const size_t set_size = pow(2, vect.size()) - 1;
        for (size_t i = 1; i < set_size; i++) {
            std::cout << "[ ";
            for (size_t j = 0; j <= vect.size(); j++) {
                if (i & (1 << j)) {
                    std::cout << vect[j] << " ";
                }
            }
            std::cout << " ]" << std::endl;
        }
    }


    void GetAllSubArrays_NonSequenced() {
        printAllSubArrays_NonSequenced({1, 2, 3, 4});
    }

    //---------------------------------------------------------------------------//

    bool _check_is_prime_1(unsigned int value) {
        if (1 == value || 2 == value)
            return true;
        else if (0 == value % 2 || 0 == value % 3)
            return false;

        for (unsigned int i = 5; i <= value / 2; i += 2) {
            std::cout << " i = " << i << std::endl;
            if (0 == value % i)
                return false;
        }
        return true;
    }

    bool _check_is_prime_2(int value) {
        if (1 == value || 2 == value)
            return true;
        else if (0 == value % 2 || 0 == value % 3)
            return false;

        for (int i = 5; (i * i) <= value; i += 2) {
            std::cout << " i = " << i << std::endl;
            if (0 == value % i)
                return false;
        }
        return true;
    }

    void CheckIsPrime() {
        /*
        for (int i : {11, 15}) {
            std::cout << "is " << i << " prime: " << std::boolalpha
                      << _check_is_prime_1(11) << ", " << _check_is_prime_2(11) << std::endl;
        }
        */

        std::cout << std::boolalpha << _check_is_prime_1(127) << std::endl;
        std::cout << std::boolalpha << _check_is_prime_2(127) << std::endl;
    }

    //---------------------------------------------------------------------------//

    bool _coins_change_problem(std::vector<int> coins, int target) {
        if (coins.empty())
            return false;

        if (const auto sum = std::accumulate(coins.begin(), coins.end(), 0); sum == target) {
            std::cout << sum << ": " << coins << std::endl;
            return true;
        }
        for (size_t i = 0; i < coins.size(); ++i) {
            std::vector<int> tmp(coins);
            tmp.erase(tmp.begin() + i);
            if (true == _coins_change_problem(tmp, target))
                return true;
        }
        return false;
    }

    void CoinsChangeProblem() {
        std::vector<int> coins{1, 1, 1, 44, 1, 1, 36, 1, 1};
        constexpr int target = 82;

        bool result = _coins_change_problem(coins, target);
        std::cout << std::boolalpha << result << std::endl;
    }

    //---------------------------------------------------------------------------//

    int _devide(int a, int b) {
        if (0 == b)
            return 0;
        int result = 0, sign = a * b > 0 ? 1 : -1;
        a = std::abs(a), b = std::abs(b);
        while (a >= b) {
            a -= b;
            ++result;
        }
        return result * sign;
    }

    void _test(int a, int b) {
        std::cout << a / b << " = " << _devide(a, b) << std::endl;

    }

    void DeviceNumeric_WithOut_Operator() {
        _test(-8, -2);
        _test(3, 2);
        _test(0, 2);
        _test(2, 3);
        _test(10, 3);
    }

    //---------------------------------------------------------------------------//

    template<typename Type>
    Type _find_smallest(Type x, Type y, Type z) {
        Type smallest = 0;
        while (x && y && z) {
            x--;
            y--;
            z--;
            smallest++;
        }
        return smallest;
    }

#if 0
    int __smallest(int x, int y)
    {
        return y + ((x - y) & ((x - y) >> (sizeof(int) * CHAR_BIT - 1)));
    }
#endif

    void FindSmallestWithoutRecursion() {
        int smallest = _find_smallest(7, 9, 12);
        std::cout << "Smallest = " << smallest << std::endl;
        // std::cout << "Smallest = " << __smallest(7, 9) << std::endl;
    }

    //---------------------------------------------------------------------------//

    template<typename T, size_t Size>
    class HeapHack {
    private:
        std::array<T, Size> data{};

    public:
        HeapHack() {
            for (size_t i = 0; i < Size; ++i)
                data[i] = std::numeric_limits<int>::max();
        }

        void add(const T &value) {
            if (data.front() > value) {
                data[0] = value;
                std::partial_sort(data.begin(), data.begin() + 1, data.end(), std::greater<int>());
            }
        }

        void print() {
            for (const T &v: data)
                std::cout << v << " ";
            std::cout << std::endl;
        }
    };

    void Find_N_Min_Elements() {
        const std::vector<int> numbers{4, 5, 6, 7, 8, 9, 10, 11, 0, -1};
        HeapHack<int, 3> mins;
        for (const auto v: numbers)
            mins.add(v);
        mins.print();
    }

    //---------------------------------------------------------------------------//

    void Find_N_Min_Elements_2() {

        constexpr int K = 3;
        const std::vector<int> numbers{4, 5, 6, 7, 8, 9, 10, 11, 0, -1};

        std::array<int, K> mins{};
        std::copy_n(numbers.cbegin(), K, mins.begin());


        std::partial_sort(mins.begin(), mins.begin() + 1, mins.end(), std::greater<int>());

        for (size_t i = K; i < std::size(numbers); i++) {
            if (mins.front() > numbers[i]) {
                mins[0] = numbers[i];
                std::partial_sort(mins.begin(), mins.begin() + 1, mins.end(), std::greater<int>());
            }
        }

        for (const auto v: mins)
            std::cout << v << " ";
        std::cout << std::endl;
    }

    //---------------------------------------------------------------------------//

    std::pair<int, int> find_min_max(const std::vector<int> &Numeric) {
        std::pair<int, int> minmax{std::numeric_limits<int>::max(), std::numeric_limits<int>::min()};
        for (const auto v: Numeric) {
            minmax.first = std::min(v, minmax.first);
            minmax.second = std::max(v, minmax.second);
        }
        return minmax;
    }

    void FindMinMax() {
        const std::vector<int> Numeric = {2, 6, 5, 8, 12, 4, 87, 24, 1, 13, 4, 45, 1};
        auto minmax = find_min_max(Numeric);
        std::cout << "{" << minmax.first << "." << minmax.second << "}" << std::endl;
    }

    //---------------------------------------------------------------------------//

    void FindTwoSmallestElements() {
        const int Numeric[] = {2, 6, 5, 8, 12, 4, 87, 24, 1};
        size_t length = std::size(Numeric);

        int min1 = Numeric[0], min2 = Numeric[1];
        if (min1 > min2)
            std::swap(min1, min2);
        for (size_t pos = 2; pos < length; pos++) {
            if (min1 > Numeric[pos]) {
                min2 = min1;
                min1 = Numeric[pos];
            } else if (min2 > Numeric[pos])
                min2 = Numeric[pos];
        }

        std::cout << min1 << "   " << min2 << std::endl;
    }

    //---------------------------------------------------------------------------//

    void __Find_N_Max_Elements(const int *data, size_t length, size_t N) {
        std::vector<int> max_elements(data, data + N);
        std::make_heap(max_elements.begin(), max_elements.end(), std::greater<>{});

        for (size_t i = N; i < length; i++) {
            if (data[i] > max_elements[0]) {
                max_elements[0] = data[i];
                std::make_heap(max_elements.begin(), max_elements.end(), std::greater<>{});
            }
        }

        for (const auto e: max_elements)
            std::cout << e << " ";
        std::cout << std::endl;
    }

    void Find_N_Max_Elements() {
        const int Numeric[] = {2, 6, 5, 8, 12, 4, 87, 24, 1, 13, 4, 45, 1};
        __Find_N_Max_Elements(Numeric, std::size(Numeric), 5);
    }


    //--------------------------------------------------------------------------------------//

    void __Find_N_Max_Element2(const int *data, size_t length, size_t N) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> result(data, data + N);
        for (size_t i = N; i < length; i++) {
            if (data[i] > result.top()) {
                result.pop();
                result.push(data[i]);
            }
        }

        while (false == result.empty()) {
            std::cout << ' ' << result.top();
            result.pop();
        }
        std::cout << std::endl;
    }

    void Find_N_Max_Elements2() {
        const int Numeric[] = {2, 6, 5, 8, 12, 4, 87, 24, 1, 13, 4, 45, 1};
        __Find_N_Max_Element2(Numeric, std::size(Numeric), 5);
    }

    //--------------------------------------------------------------------------------------//

    void MaxPairSumInArray() {
        const int Numeric[] = {4, 2, 6, 1};
        size_t length = std::size(Numeric);

        int max1 = std::numeric_limits<int>::min(), max2 = std::numeric_limits<int>::min();
        for (size_t pos = 0; pos < length; pos++) {
            if (Numeric[pos] > max1) {
                max2 = max1;
                max1 = Numeric[pos];
            } else if (Numeric[pos] > max2)
                max2 = Numeric[pos];
        }

        std::cout << max2 + max1 << std::endl;
    }

    //======================================================================================//

    template<typename T>
    void removeElement(std::vector<T> &nums, const T value) {
        size_t pos = 0;
        for (T &entry: nums)
            if (value != entry)
                std::swap(nums[pos++], entry);

        nums.resize(pos);
        nums.shrink_to_fit();
    }

    void RemoveElement() {
        // std::vector nums { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
        std::vector nums{1, 2, 3, 1, 2, 3, 1, 2, 3, 4, 5, 6, 7, 2, 2, 2, 33};
        std::cout << nums << std::endl;

        removeElement(nums, 2);
        std::cout << nums << std::endl;
    }
}

namespace Numeric
{
    template<typename T>
    void removeDuplicates(std::vector<T> &nums)
    {
        std::unordered_set<T> duplicates{};
        size_t pos = 0;
        for (size_t idx = 0; idx < nums.size(); ++idx)
            if (true == duplicates.insert(nums[idx]).second)
                std::swap(nums[pos++], nums[idx]);

        nums.resize(pos);
        nums.shrink_to_fit();
    }

    void RemoveDuplicates()
    {
        // std::vector nums { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
        std::vector nums{0, 1, 1, 2, 2, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5};
        std::cout << nums << std::endl;

        removeDuplicates(nums);
        std::cout << nums << std::endl;
    }
}

namespace Numeric
{
    bool contains_duplicate(const std::vector<int> &nums) {
        std::unordered_set<int> set(nums.begin(), nums.end());
        return nums.size() != set.size();
    }

    void Contains_Duplicate()
    {
        for (const std::vector<int> &values: std::vector<std::vector<int>>{
                {1, 2, 3, 4, 5},
                {1, 2, 3, 4, 5, 3}
        }) {
            std::cout << std::boolalpha << contains_duplicate(values) << std::endl;
        }
    }
}

namespace Numeric
{
    size_t remove_duplicates_sorted(std::vector<int> &nums)
    {
        size_t pos = 0;
        if (nums.empty())
            return pos;
        for (size_t idx = 1; idx < nums.size(); ++idx) {
            if (nums[pos] != nums[idx]) {
                nums[++pos] = nums[idx];
            }
        }
        nums.resize(++pos);
        nums.shrink_to_fit();
        return pos;
    }

    void RemoveDuplicates_SortedArray()
    {
        for (auto& [values, expected]: std::vector<VectorPair<int>> {
                {{}, {}},
                {{0, 1, 2}, {0, 1, 2}},
                {{0, 0, 1, 1, 1, 2, 2, 3, 3, 4}, {0, 1, 2, 3, 4}} ,
                {{0, 1, 1, 2, 2, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5}, {0, 1, 2, 3, 4, 5}}
        })
        {
            remove_duplicates_sorted(values);
            if (values != expected) {
                std::cerr << expected << " != " << expected << std::endl;
                return;
            }
        }
        std::cout << "OK: All tests passed\n";
    }
}

namespace Numeric
{
    void DeleteFromArray()
    {
        std::vector<int> data = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

        const auto pred = [](int v) { return 0 == v % 2; };

        size_t pos = 0;
        for (auto &v: data) {
            if (!pred(v))
                std::swap(data[pos++], v);
        }

        data.resize(pos);
        std::cout << data << std::endl;
    }
}

namespace Numeric
{
    size_t _longest_consecutive_sequence(const std::vector<int> &Numeric)
    {
        std::unordered_set<int> tmp(Numeric.begin(), Numeric.end());
        size_t count = 0;
        for (int i: Numeric) {
            size_t len = 0;
            int val = i;
            while (tmp.end() != tmp.find(val++))
                len++;
            count = std::max(count, len);
        }
        return count;
    }

    void Longest_Consecutive_Sequence()
    {
        const std::vector<int> Numeric = {100, 4, 200, 1, 3, 2};

        size_t count = _longest_consecutive_sequence(Numeric);
        std::cout << count << std::endl;
    }
}

namespace Numeric
{
    size_t findLongestSubArray(const std::vector<int> &vect1,
                               const std::vector<int> &vect2)
    {
        size_t maxLen{0};
        for (size_t size1 = vect1.size(), i = 0; i < size1; ++i)
        {
            for (size_t size2 = vect2.size(), j = 0 ; j < size2; ++j)
            {
                size_t n{i}, m{j};
                while (size1 > n && size2 > m && vect1[n++] == vect2[m++]) {
                    maxLen = std::max(maxLen, n - i);
                }
            }
        }
        return maxLen;
    }

    void FindLongestSubArray()
    {
        const std::vector<int> a = {1, 3, 4, 5, 2}, b{1, 2, 3, 4, 5};
        std::cout << findLongestSubArray(a, b) << std::endl;
    }
}

namespace Numeric
{
    using VectorSizePair = std::pair<std::vector<int>, size_t>;

    size_t maxSubarrayLength(const std::vector<int>& nums,
                             const size_t k)
    {
        // Dictionary to keep track of the count of each number in the current window
        std::unordered_map<int, size_t> countMap;

        // Variable to store the maximum length found
        size_t maxLength = 0;

        // Two pointers defining the current window's boundaries
        for (size_t left = 0, right = 0, size = nums.size(); right < size; ++right)
        {
            // Increment the count of the rightmost element in the current window
            ++countMap[nums[right]];

            // If the count of the current element exceeds k, shrink the window from the left
            while (countMap[nums[right]] > k)
            {
                --countMap[nums[left]];
                ++left;  // Move the left pointer to the right
            }
            // Update the maximum length if the current window is larger
            maxLength = std::max(maxLength, right - left + 1);
        }
        // Return the maximum length of the sub-array
        return maxLength;
    }

    //  Необходимо найти максимальную длину под-массива такого что бы в нем было не более чем 'K' уникальных элементов
    void FindLongestSubArray_K_UniqueElements()
    {
        for (const std::pair<VectorSizePair, size_t> &data: std::vector<std::pair<VectorSizePair, size_t> >{
                {{{1, 2, 2, 3, 1, 2, 3},       2}, 5},
                {{{1, 2, 2, 3, 1, 3, 3},       2}, 6},
                {{{1, 1, 2, 2, 1, 2, 1},       2}, 4},
                {{{0},       2}, 1},
                {{{},       0}, 0},
        }) {
            const auto &[values, K] = data.first;
            if (const auto actual = maxSubarrayLength(values, K); actual != data.second)
            {
                std::cout << "Expected value is " << data.second << ", Actual: " << actual << std::endl;
            }
        }
        std::cout << "OK: All tests passed\n";
    }
}
namespace Numeric
{
    size_t findLongestSubArrayFromPos(const std::vector<int> &vect1,
                                      const size_t start,
                                      const std::vector<int> &vect2) {
        const size_t size1{vect1.size()}, size2{vect2.size()};
        size_t maxLen{0};
        for (size_t j = 0; j < size2; ++j) {
            size_t n{start}, m{j};
            while (size1 > n && size2 > m && vect1[n++] == vect2[m++]) {
                maxLen = std::max(maxLen, n - start);
            }
        }
        return maxLen;
    }

    size_t splitArray(const std::vector<int> &vect1,
                      const std::vector<int> &vect2) {
        size_t count{0}, i{0};
        while (vect1.size() > i) {
            i += findLongestSubArrayFromPos(vect1, i, vect2);
            ++count;
        }
        return count;
    }

    // INFO: Assuming that toCut and desired contains the same set of unique numbers
    void SplitArrayToPieces_FindNumber_ByExample()
    {
        const std::vector<int> toCut = {1, 3, 4, 2}, desired{1, 2, 3, 4};

        std::cout << splitArray(toCut, desired) << std::endl;
    }
}

namespace Numeric
{
    size_t _longest_increasing_subsequence_1(const std::vector<int> &Numeric) {
        // create an empty ordered set S. ith element in S is defined as the
        // smallest integer that ends an increasing sequence of length i
        std::set<int> tmp;

        for (int val: Numeric) {
            auto [iter, ok] = tmp.insert(val);
            // 1. If element IS NOT inserted at the END, then delete next greater element from set
            // 2. Ignore the current element if already present in the set
            if (ok && tmp.end() != std::next(iter))
                tmp.erase(std::next(iter));
        }
        return tmp.size();
    }

    /** Solution:
    The O(nlogn) solution is less obvious.

    If we consider building a subsequence iteratively, we have two situations.
    Either the next element is strictly higher, in which case we can simply append it.

    If it is not, we still want to remember it and we can do that by replacing the next higher value in the subsequence.

    This works because we only ever decrease values this way:
    - we won't break previous subsequences this way
    - we won't accidentally skip over potential subsequences
    **/

    size_t _longest_increasing_subsequence_2(const std::vector<int> &numbers) {
        std::vector<int> path;
        for (int64_t i = 0; i < std::ssize(numbers); ++i) {
            // Current element is higher than the tail of the path.
            if (path.empty() || path.back() < numbers[i]) {
                path.push_back(numbers[i]);
                continue;
            }

            // Find the element to overwrite
            auto it = std::upper_bound(path.begin(), path.end(), numbers[i], [](int l, int r) {
                return l <= r;
            });

            // it != path.end() because path.back() >= nums[i];
            *it = numbers[i];
        }
        return path.size();
    }

    void Find_Longest_Increasing_Subsequence() {
        std::vector<std::pair<std::vector<int>, size_t>> testData{
                {{1,  2,  3},                         3},
                {{3,  2,  1},                         1},
                {{2,  8,  4, 1,  9,  3,  5},          3},
                {{2,  1,  4, 3,  6,  5,  8,  7,  9},  5},
                {{1,  1,  1, 1},                      1},
                {{10, 22, 9, 33, 21, 50, 41, 60, 80}, 6},
                {{1,  2,  2, 3,  4,  4},              4}
        };
        for (const auto &[data, expectedResult]: testData) {
            std::cout << _longest_increasing_subsequence_1(data) << " | "
                      << _longest_increasing_subsequence_2(data) << " | "
                      << expectedResult << std::endl;
        }
    }

    //--------------------------------------------------------------------------------------//

    void find_longest_increasing_subsequence_1(const std::vector<int> &Numeric) {
        assert(false == Numeric.empty());
        for (size_t i = 1; i < Numeric.size(); i++) {
            if (Numeric[i - 1] > Numeric[i])
                std::cout << Numeric[i - 1] << std::endl;
        }
    }

    void Find_Longest_Increasing_Subsequence_1() {
        const std::vector<int> Numeric = {1, 2, 33, 3, 4, 5, 6, 66, 7, 8, 9};
        find_longest_increasing_subsequence_1(Numeric);
    }

    //--------------------------------------------------------------------------------------//

    // Second-largest element
    // Just using classing min_heap approach
    void _next_larger_element(const std::vector<int> &numbers) {
        std::array<int, 2> minHeap{numbers[0], numbers[1]};
        for (size_t idx = minHeap.size(); idx < numbers.size(); ++idx) {
            minHeap.front() = minHeap.front() > numbers[idx] ? minHeap.front() : numbers[idx];
            std::make_heap(minHeap.begin(), minHeap.end(), [](int x, int y) { return y < x; });
        }

        std::cout << minHeap.front() << std::endl;
    }

    void _next_larger_element2(const std::vector<int> &numbers) {
        std::array<int, 2> mins{numbers[0], numbers[1]};
        if (mins[0] > mins[1]) std::swap(mins[0], mins[1]);

        for (size_t idx = 2; idx < numbers.size(); ++idx) {
            if (numbers[idx] > mins[0]) mins[0] = numbers[idx];
            if (mins[0] > mins[1]) std::swap(mins[0], mins[1]);
        }

        std::cout << mins.front() << std::endl;
    }

    void NextLargerElement() {
        const std::vector<int> Numeric = {1, 3, 2, 4, 6, 9, 5, 11};
        _next_larger_element(Numeric);
        _next_larger_element2(Numeric);
    }

    //--------------------------------------------------------------------------------------//

    // Function to print all distinct combinations of length k
    void recur(std::vector<int> data, std::string out, int i, int k) {
        if (k > static_cast<int>(data.size()))
            return;
        else if (k == 0) {
            std::cout << out << std::endl;
            return;
        }

        // start from next index till last index
        for (int index = i; index < static_cast<int>(data.size()); index++) {
            // add current element data[j] to solution & recur for next index (j+1) with one less element (k-1)
            recur(data, out + " " + std::to_string(data[index]), index + 1, k - 1);

            // uncomment below code to handle duplicates
            // while (j < data.size()) - 1 && data[j] == data[j + 1])
            //	j++;
        }
    }

    void Find_All_Distinct_Combinations_LengthK() {
        const std::vector<int> Numeric = {1, 2, 3};
        recur(Numeric, "", 0, 2);
    }

    //--------------------------------------------------------------------------------------//

    bool _is_array_consecutive(const std::vector<int> &array) { // Array shall not contain duplicaties
        int result = 0, min = array[0];
        // Following loop is to:
        // 1. Determine min value
        // 2. Calculate difference between sum of all elements in range {1... length}
        //    and sum of all elements in the input array
        for (size_t i = 0; i < array.size(); result += i++) {
            result -= array[i];
            min = std::min(min, array[i]);
        }

        // Here we have to update 'result' value since the input array
        // could start not from 1 but from 100500 for example.
        // 'min' variable is the first value of the potential consecutive array
        return 0 == (result + min * array.size());
    }

    bool _is_array_consecutive_2(const std::vector<int> &Numeric) {
        std::unordered_set<int> tmp(Numeric.begin(), Numeric.end());
        const auto minmax = std::minmax_element(Numeric.begin(), Numeric.end());
        for (int i = *minmax.first; i < *minmax.second; ++i) {
            if (tmp.end() == tmp.find(i))
                return false;
        }
        return true;
    }

    bool _is_array_consecutive_3(const std::vector<int> &Numeric) {
        std::set<int> tmp(Numeric.begin(), Numeric.end());
        for (int first = *tmp.begin(), last = *std::prev(tmp.end()); first < last; ++first) {
            if (tmp.end() == tmp.find(first))
                return false;
        }
        return true;
    }

    void Is_Array_Elements_Consecutive() {
        std::vector<std::vector<int>> testData{
                {1,  2,  3},
                {-1, -2, -3, -4, -4, -6},
                {1,  2,  4},
                {5,  4,  1,  3,  2}
        };
        for (const std::vector<int> &data: testData) {
            std::cout << "\nIs Consecutive 1: " << std::boolalpha << _is_array_consecutive(data) << std::endl;
            std::cout << "Is Consecutive 2: " << std::boolalpha << _is_array_consecutive_2(data) << std::endl;
            std::cout << "Is Consecutive 3: " << std::boolalpha << _is_array_consecutive_3(data) << std::endl;
        }

    }

    //--------------------------------------------------------------------------------------//

    void Sum_Of_ConsecutiveNumeric() {
        // len - length of sequance
        // start_number - first number of the sequance
        // ( len  + (len + 1) ) / 2 + (start_number * len)

        std::cout << "Sum of 0 - 10: " << (10 * (10 + 1)) / 2 + (0 * 10) << std::endl;
        std::cout << "Sum of 5 - 15: " << (10 * (10 + 1)) / 2 + (5 * 10) << std::endl;
        std::cout << "Sum of 15 - 20: " << (5 * (5 + 1)) / 2 + (15 * 5) << std::endl;
    }

    //--------------------------------------------------------------------------------------//

    void __MiniMaxSum(std::vector<long> v) {
        long long int sum = 0;
        const auto x = std::minmax_element(v.begin(), v.end());
        for (long long i: v)
            sum += i;
        std::cout << sum - *x.second << " " << sum - *x.first << std::endl;
    }

    void MiniMaxSum_Of4() {
        __MiniMaxSum({1, 2, 3, 4, 5});
    }

    //--------------------------------------------------------------------------------------//

    void Find_Sum_All_Numeric() {
        const auto test = [](int max) {
            std::vector<int> values;
            values.resize(max);
            std::iota(values.begin(), values.end(), 1);

            const int sum_expected = std::accumulate(values.begin(), values.end(), 0);
            const int sum_actual = (max * (max + 1)) / 2;

            if (sum_expected == sum_actual)
                std::cout << "Test for values [1 - " << max << "]. Passed" << std::endl;
        };

        std::vector<int> params;
        FillVecor(params, 20, 20, 1000);

        for (auto i: params) {
            test(i);
        }
    }
}

namespace Numeric
{
    int find_duplicate_1(const std::vector<int> &values)
    {
        std::unordered_set<int> uniques;
        uniques.reserve(values.size());
        for (int v: values)
            if (!uniques.emplace(v).second)
                return v;
        return 0;
    }

    // TODO: Works only in case is only ONE duplicate
    //       We know that ARRAY contains 'SIZE - 1' sequential elements starting from number 1 --> sum of that elements
    //       can be found using (N + 1) * N / 2 (where N == SIZE - 1)
    int find_duplicate_2(const std::vector<int> &values)
    {
        const int sum = std::accumulate(values.cbegin(), values.cend(), 0);
        return sum - static_cast<int>((values.size() * (values.size() - 1)) / 2);
    }

    int find_duplicate_3(const std::vector<int> &values)
    {
        int tortoise = values[0], hare = values[0];

        // Advance until the tortoise meets the hare.
        do {
            tortoise = values[tortoise];
            hare = values[values[hare]];
        } while (tortoise != hare);

        // Reset the tortoise and move both one step at a time, until they meet.
        tortoise = values[0];
        while (tortoise != hare) {
            tortoise = values[tortoise];
            hare = values[hare];
        }

        return hare;
    }

    int find_duplicate_4(std::vector<int> &values)
    {
        while(values[0]!=values[values[0]])
            std::swap(values[0],values[values[0]]);
        return values.front();
    }

    /// Given an array of length N + 1 that contains the integers 1..n with one duplicate, return the duplicate.
    /// All values a unique with exception of the one duplicate
    /// Solution should have O(n) time complexity and O(1) space complexity.
    void FindTheDuplicateValue()
    {
        for (auto &[values, expected]: std::vector<std::pair<std::vector<int>, int>>{
                {{1, 1, 2},                      1},
                {{3, 1, 1, 2},                   1},
                {{7, 1, 6, 9, 3, 4, 9, 5, 2, 8}, 9},
                {{5, 1, 2, 3, 4, 5},             5},
                {{1,3,4,2,2},                    2},
                {{3,1,3,4,2},                    3},
        }) {
            std::cout << find_duplicate_1(values) << " | "
                      << find_duplicate_2(values) << " | "
                      << find_duplicate_3(values) << " | "
                      << find_duplicate_4(values) << " | " << expected << std::endl;
        }
    }
}

namespace Numeric
{
    int search(const std::vector<int> &data) {
        int left = 0, right = data.size() - 1;
        int mid;
        while ((right - left) > 1) {
            mid = (left + right) / 2;
            if ((data[left] - left) != (data[mid] - mid))
                right = mid;
            else if ((data[right] - right) != (data[mid] - mid))
                left = mid;
        }
        return (left + data[0] + 1);
    }

    void FindTheMissingNumber_SortedArray() {
        {
            std::vector<int> data = {1, 2, 3, 4, 5, 6, 8};
            std::cout << "Missing number:" << search(data) << std::endl;
        }
        {
            std::vector<int> data = {3, 4, 5, 6, 7, 8, 9, 10, 12, 13};
            std::cout << "Missing number:" << search(data) << std::endl;
        }
    }
}

namespace Numeric
{
    int __search1(const std::vector<int>& values)
    {
        int sum_expected = static_cast<int>((values.size() + 1) * (values.size() + 2)) / 2;
        const int sum = std::accumulate(values.begin(), values.end(), 0);
        return sum_expected - sum;
    }

    int __search2(const std::vector<int>& values)
    {
        int result = 1;
        for (size_t index = 2; index <= (values.size() + 1); index++) {
            result += (index - values[index - 2]);
        }
        return result;
    }

    void FindTheMissingNumber_Unsorted()
    {
        for (const std::vector<int> &values: std::vector<std::vector<int>>{
                {1,2,3,5}, // 4
                {5,4,3,1},   // 2
        }) {
            std::cout << __search1(values) << "  " << __search2(values) << std::endl;
        }
    }
}


namespace Numeric
{
    int _find_missing_element(const std::vector<int>& values)
    {
        int sum = 1, min = std::numeric_limits<int>::max();

        // Loop to determine min value in the given array and
        // sum will keep value of the missing element in suggestion that
        // array has elements from (1 ... till ... length)
        for (size_t index = 2; index < (values.size() + 2); index++) {
            sum += (index - values[index - 2]);
            min = std::min(min, values[index - 2]);
        }
        return (sum + (min - 1) * (values.size() + 1));
    }

    int _find_missing_element_2(const std::vector<int>& values)
    {
        int sum = 0, min = std::numeric_limits<int>::max();
        for (int v: values) {
            sum += v;
            min = std::min(min, v);
        }

        const int diff = ((values.size() + 1) * (values.size() + 2)) / 2 - sum;
        return (diff + (min - 1) * (values.size() + 1));
    }


    int _find_missing_element_3(const std::vector<int>& values)
    {
        auto min = *std::min_element(values.begin(), values.end());
        auto sum = std::accumulate(values.begin(), values.end(), 0);

        int diff = ((values.size() + 1) * (values.size() + 2)) / 2 - sum;
        return (diff + (min - 1) * (values.size() + 1));
    }

    void FindTheMissingNumber_Unsorted_AnyRange() {
        {
            std::vector<int> Numeric = {1, 2, 3, 5};
            std::cout << _find_missing_element(Numeric) << std::endl;
            std::cout << _find_missing_element_2(Numeric) << std::endl;
            std::cout << _find_missing_element_3(Numeric) << std::endl;
        }
        {
            std::vector<int> Numeric = {4, 5, 6, 7, 8, 9, 11, 12};
            std::cout << _find_missing_element(Numeric) << std::endl;
            std::cout << _find_missing_element_2(Numeric) << std::endl;
            std::cout << _find_missing_element_3(Numeric) << std::endl;
        }
    }
}

namespace Numeric
{
    int missing_number(const std::vector<int>& values)
    {
        const int sum = std::accumulate(values.cbegin(), values.cend(), 0);
        return static_cast<int>((values.size()  * (values.size() + 1)) / 2) - sum;
    }

    /**
     * Given an array nums containing n distinct numbers in the range [0, n],
     * return the only number in the range that is missing from the array.
     * Example 1:
     *   nums = [3,0,1] -> 2
     *   nums = [0,1]   -> 2
     *   nums = [9,6,4,2,3,5,7,0,1]   -> 8
    */
    void MissingNumber()
    {
        for (const std::vector<int> &values: std::vector<std::vector<int>>{
                {3,0,1}, // 2
                {0,1},   // 2
                {9,6,4,2,3,5,7,0,1},   // 8
        }) {
            std::cout << missing_number(values) << std::endl;
        }
    }
}

namespace Numeric
{
    int __Find_K_MissingNumber(const int *data, size_t length, size_t K)
    {
        auto minmax = std::minmax_element(data, data + length);
        int diff = *minmax.second - *minmax.first, min = *minmax.first;
        std::vector<int> tmp(diff + 1);
        for (size_t i = 0; i < length; i++)
            tmp[data[i] - min] = 1;
        for (int i = 0; i <= diff; i++) {
            if (0 == tmp[i] && 0 == --K) {
                std::cout << i + min << std::endl;
                return i + min;
            }
        }
        return 0;
    }

    void __Find_K_MissingNumber_2(const int *data, size_t length, size_t K) {
        auto [min, max] = std::minmax_element(data, data + length);
        std::unordered_set<int> set(data, data + length);
        for (auto i = *min; i < *max; ++i) {
            if (auto result = set.find(i); result == set.end() && 0 == --K) {
                std::cout << i << std::endl;
                return;
            }
        }
        std::cout << "Not found" << std::endl;
    }

    void Find_K_MissingNumber() {
        const int data[] = {2, 4, 10, 7};
        __Find_K_MissingNumber(data, std::size(data), 5);
        __Find_K_MissingNumber_2(data, std::size(data), 5);
    }

    //--------------------------------------------------------------------------------------//

    int __Find_K_MissingNumber_Sorted(const int *data, size_t length, size_t K) {
        int expected = data[0], count = 0;
        for (size_t index = 0; index < length; index++) {
            if (expected++ != data[index]) {
                if (static_cast<int>(K) == ++count)
                    return expected - 1;
                index--;
            }
        }
        return 0;
    }

    int __Find_K_MissingNumber_Sorted2(const int *data, size_t length, size_t K) {
        int expected = data[0];
        size_t index = 0;
        while (index < length) {
            if (data[index] != expected) {
                if (0 == --K)
                    return expected;
            } else {
                index++;
            }
            expected++;
        }
        return 0;
    }

    void Find_K_MissingNumber_Sorted() {
        const int data[] = {1, 2, 4, 5, 6, 8, 10, 13, 20};
        std::cout << "Missing element = " << __Find_K_MissingNumber_Sorted(data, std::size(data), 5) << std::endl;
        std::cout << "Missing element = " << __Find_K_MissingNumber_Sorted2(data, std::size(data), 5) << std::endl;


        std::cout << "Missing element = " << __Find_K_MissingNumber(data, std::size(data), 5) << std::endl;
    }

    //--------------------------------------------------------------------------------------//

    void Find_Multiplier_Pair() {
        constexpr int X = 20;
        const std::vector<int> Numeric = {1, 23, 43, 52, 67, 8, 2, 99, 34, 41, 76, 3, 56, 34, 57, 23, 4656, 2342, 11, 456, 4, 2,
                                          76, 9, 5};
        std::unordered_set<int> tmp;
        auto iter = tmp.begin();
        for (const auto value: Numeric) {
            if (0 == X % value) {
                iter = tmp.find(X / value);
                if (tmp.end() != iter) {
                    std::cout << "{" << value << ", " << *iter << "}" << std::endl;
                    return;
                }
                tmp.insert(value);
            }
        }
    }

    void Find_Multiplier_Pair2() {
        constexpr int X = 2000;
        const std::vector<int> Numeric = {1, 23, 43, 5, 67, 8, 2, 200, 99, 34, 41, 76, 3, 56, 34, 57, 23, 4656, 2342, 11, 456,
                                          423, 2, 76, 9, 4, 10};
        int tmp[X] = {0};
        for (const auto value: Numeric) {
            if (0 == X % value) {
                if (1 == tmp[X / value]) {
                    std::cout << "{" << X / value << ", " << value << "}" << std::endl;
                    return;
                } else
                    tmp[value] = 1;
            }
        }
    }

    //--------------------------------------------------------------------------------------//

    int Find_DifferentPairs_SumK(const std::vector<int> &data, int K) {
        std::unordered_map<int, int> tmp;// = { 0,0 };
        for (int i: data)
            tmp[i]++;
        int count = 0;
        for (int key: data) {
            if (auto iter = tmp.find(K - key); tmp.end() != iter) {
                count += (key == (K - key)) ? iter->second - 1 : iter->second;
                std::cout << key << "  " << count << std::endl;
            }
        }
        return count / 2;
    }

    void Find_DifferentPairs_SumK_2(const std::vector<int> &data, int K) {
        std::unordered_map<int, int> tmp;
        for (int key: data) {
            if (auto iter = tmp.find(K - key); tmp.end() != iter) {
                iter->second = key;
            } else {
                [[maybe_unused]]
                auto v = tmp.emplace(key, 0);
            }
        }

        for (const auto &[k, v]: tmp)
            std::cout << k << " = " << v << std::endl;
    }

    void Find_DifferentPairs_SumK() {
        using TestData = std::pair<std::vector<int>, int>;
        for (const TestData &data: std::vector<TestData>{
                {{1, 2, 3, 4}, 5}
        }) {
            // Find_DifferentPairs_SumK(Numeric, K);
            Find_DifferentPairs_SumK_2(data.first, data.second);
        }
    }
}


namespace Numeric
{

    std::pair<int32_t, int32_t> pair_sum(const std::vector<int32_t>& values, const int32_t K)
    {
        for (int32_t idxLeft = 0, idxRight = values.size() - 1; idxLeft < idxRight;) {
            if (values[idxLeft] + values[idxRight] == K) {
                return { values[idxLeft], values[idxRight] };
            }
            if (values[idxLeft] + values[idxRight] < K) {
                ++idxLeft;
            } else {
                --idxRight;
            }
        }
        return {-1 , -1};
    }

    void Find_Pair_SumX_Sorted()
    {
        for (const auto& [values, K]: VectorOfPairs<std::vector<int32_t>, int32_t>{
            { {2,7,11,15}, 9 },
            {{ 2, 4, 5, 6, 7, 8, 9, 11 }, 12}

        }) {
            const auto [first, second] = pair_sum(values, K);
            std::cout << '[' << values << " ] = { " << first << ", " << second << " }\n";
        }
    }
}

namespace Numeric
{
    void Find_3_Elements_SumX_Sorted()
    {
        const std::vector<int> Numeric = {1, 4, 45, 6, 10, 8};
        int sum = 22;

        std::unordered_set<int> set;
        for (size_t i = 0; i < Numeric.size(); i++) {
            set.clear();
            for (size_t n = 0; n < Numeric.size(); n++) {
                if (n == i)
                    continue;
                if (set.end() != set.find(sum - Numeric[i] - Numeric[n])) {
                    std::cout << "OK: " << Numeric[i] << "  " << Numeric[n] << "  " << sum - Numeric[i] - Numeric[n] << std::endl;
                    return;
                } else {
                    set.insert(Numeric[n]);
                }
            }
        }
        std::cout << "Done" << std::endl;
    }

    //--------------------------------------------------------------------------------------//

    void Find_3_Elements_SumX_Unsorted() {
        const std::vector<int> Numeric = {1, 4, 45, 6, 10, 8};
        int SUM = 20;

        auto have_some = [&Numeric](std::unordered_set<int> &set, const int sum, size_t id_skip) {
            set.clear();
            for (size_t i = 0; i < Numeric.size(); ++i) {
                if (id_skip == i)
                    continue;
                if (const auto iter = set.find(sum - Numeric[i]); set.end() != iter) {
                    std::cout << "[" << Numeric[i] << ", " << *iter << ", ";
                    return true;
                } else {
                    set.insert(Numeric[i]);
                }
            }
            return false;
        };

        std::unordered_set<int> set;
        for (size_t i = 0; i < Numeric.size(); ++i) {
            if (true == have_some(set, SUM - Numeric[i], i)) {
                std::cout << Numeric[i] << "]\n";
                break;
            }
        }
        std::cout << "Done" << std::endl;
    }

    //--------------------------------------------------------------------------------------//

    int __SmallestMissingPositiveNumber(const std::vector<int> &A) {
        const auto minmax = std::minmax_element(A.begin(), A.end());
        int min = *minmax.first, max = *minmax.second;
        if (1 > max || min > 1)
            return 1;

        std::unordered_set<int> set(A.begin(), A.end());
        for (int i = std::max(1, min); i < max; i++)
            if (set.end() == set.find(i))
                return i;

        return max + 1;
    }

    int __SmallestMissingPositiveNumber2(const std::vector<int> &A) {
        std::unordered_set<int> set;
        int min = std::numeric_limits<int>::max(), max = std::numeric_limits<int>::min();
        for (int i: A) {
            if (i > max)
                max = i;
            if (min > i)
                min = i;
            if (i > 0)
                set.insert(i);
        }
        if (1 > max || min > 1)
            return 1;

        for (int i = std::max(1, min); i < max; i++)
            if (set.end() == set.find(i))
                return i;

        return max + 1;
    }

    int __SmallestMissingPositiveNumber_FAST(std::vector<int> nums) {
        const int size = static_cast<int>(nums.size());
        std::ios::sync_with_stdio(0);
        std::cin.tie(0);
        for (int i = 0; i < size; ++i)
            while (nums[i] > 0 && nums[i] <= size && nums[i] != nums[nums[i] - 1])
                std::swap(nums[i], nums[nums[i] - 1]);

        for (int i = 0; i < size; ++i)
            if (nums[i] != i + 1)
                return i + 1;

        return size + 1;
    }

    void Find_Smallest_Missing_Positive_Number() {
        for (const std::vector<int> &numbers: std::vector<std::vector<int>>{
                {-1,      0, 1},
                {1,       3, 6,       4, 1, 2},
                {3,       4, 5,       6},
                {-999999, 4, 9999999, 6}
        }) {
            std::cout << __SmallestMissingPositiveNumber(numbers) << " "
                      << __SmallestMissingPositiveNumber2(numbers) << " "
                      << __SmallestMissingPositiveNumber_FAST(numbers)
                      << std::endl;
        }
    }

    //--------------------------------------------------------------------------------------//

    // Note: Sequence should start from 1
    void _find_repeating_and_missing(const std::vector<int> &values) {
        std::unordered_set<int> nums;
        int dif = 0, dup_idx = -1;
        for (size_t idx = 0; idx < values.size(); ++idx) {
            dif += idx - values[idx] + 1;
            if (-1 == dup_idx && !nums.insert(values[idx]).second)
                dup_idx = idx;
        }

        const int dup = values[dup_idx];
        std::cout << "Reaping symbol: " << dup << ", Missing: " << dup + dif << std::endl;
    }

    void _find_repeating_and_missing_ex(const std::vector<int> &values) {
        std::unordered_set<int> nums;
        int sum = 0, dup = 0, min = std::numeric_limits<int>::max();
        for (const int val: values) {
            min = std::min(val, min);
            sum += val;
            if (0 == dup && false == nums.insert(val).second)
                dup = val;
        }

        auto size = values.size();
        auto sum_expected = (size * (size + 1)) / 2 + size * (min - 1);

        std::cout << "Reaping symbol: " << dup << ", Missing: " << dup + sum_expected - sum << std::endl;
    }

    void Find_Repeating_And_Missing() {
        {
            std::vector<int> Numeric = {8, 7, 7, 4, 5, 6, 2, 1};
            _find_repeating_and_missing(Numeric);
        }
        {
            std::vector<int> Numeric = {5, 6, 7, 6, 9};
            _find_repeating_and_missing_ex(Numeric);
        }
    }

    //--------------------------------------------------------------------------------------//

    struct PairHash {
        std::size_t operator()(const std::pair<int, int> &p) const noexcept {
            return std::hash<int>()(p.first) ^ std::hash<int>()(p.second);
        }
    };

    void _find_repeating_and_missing(const std::vector<std::pair<int, int>> &pairs) {
        std::unordered_set<std::pair<int, int>, PairHash> duplicates;

        for (const auto &pair: pairs) {
            duplicates.insert(pair);
            if (duplicates.end() != duplicates.find({pair.second, pair.first}))
                std::cout << "{" << pair.first << "," << pair.second << "} | " << "{" << pair.second << "," << pair.first << "}"
                          << std::endl;
        }
    }

    void Find_All_Symmetric_Pairs_InArray() {
        std::vector<std::pair<int, int>> pairs = {{3, 4},
                                                  {1, 2},
                                                  {5, 2},
                                                  {7, 10},
                                                  {4, 3},
                                                  {2, 5}};
        _find_repeating_and_missing(pairs);
    }

    //--------------------------------------------------------------------------------------//

    void __Add_One_To_Integer_Array(int *data, size_t length) {
        int pos = static_cast<int>(length);
        while (9 == data[--pos] && pos) {
            data[pos] = 0;
        }
        if (-1 == pos)
            std::cout << 1;
        else
            data[pos]++;

        // PRINT
        for (pos = 0; pos < static_cast<int>(length); ++pos)
            std::cout << data[pos];
        std::cout << std::endl;
    }


    void __Add_One_To_Integer_Array_2(std::span<int> data) {
        std::deque<int> result{data.begin(), data.end()};
        int pos = static_cast<int>(result.size());
        while (9 == data[--pos] && pos) {
            result[pos] = 0;
        }
        if (-1 == pos)
            result.push_front(1);
        else
            result[pos]++;

        std::cout << result << std::endl;

    }

    void Add_One_To_Integer_ArrayTest() {
        int data[] = {1, 2, 3, 4, 5, 6, 7, 9, 9, 4};

        // __Add_One_To_Integer_Array(data2, 4);
        __Add_One_To_Integer_Array_2(data);
    }

    //--------------------------------------------------------------------------------------//

    std::vector<int> product_of_array_except_self(const std::vector<int> &values) {
        std::vector<int> result(values.size(), 0);
        int allProd = 1, zeros = 0, zeroIdx = -1;
        for (int idx = 0; idx < std::ssize(values); ++idx) {
            if (0 != values[idx])
                allProd *= values[idx];
            else {
                zeroIdx = idx;
                ++zeros;
            }
        }

        if (0 == zeros) {
            for (int i = 0; i < std::ssize(values); ++i)
                result[i] = allProd / values[i];
        } else if (1 == zeros)
            result[zeroIdx] = allProd;

        return result;
    }

    std::vector<int> product_of_array_except_self_ex(const std::vector<int> &values) {
        const int n = std::ssize(values);
        std::vector<int> result(n, 1);

        for (int idx = 1; idx != n; ++idx)
            result[idx] = result[idx - 1] * values[idx - 1];

        for (int r = 1, i = n - 1; i >= 0; --i) {
            result[i] *= r;
            r *= values[i];
        }

        return result;
    }

    void Product_Of_All_Numeric_Except_N() {
        for (const std::vector<int> &values: std::vector<std::vector<int>>{
                {1,  2, 3, 4},
                {1,  2, 3, 4,  5},
                {-1, 1, 0, -3, 3},
                {-1, 1, 0, -3, 3, 0},
                {0,  0, 0}
        }) {
            const std::vector<int> result1 = product_of_array_except_self(values);
            const std::vector<int> result2 = product_of_array_except_self_ex(values);

            std::cout << result1 << std::endl << result2 << std::endl << std::endl;
        }
    }

    //--------------------------------------------------------------------------------------//

    void Find_Elements_Occured_Once() {
        int Numeric[] = {1, 1, 2, 2, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 9, 9, 9};

        std::unordered_set<int> tmp;
        for (int val: Numeric)
            if (auto result = tmp.insert(val); false == result.second)
                tmp.erase(result.first);

        for (int i: tmp)
            std::cout << i << std::endl;
    }


    void Find_ONE_Element_Occured_Once() {
        {
            int Numeric[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9, 22, 1, 2, 3, 4, 5,
                             6, 7, 8, 9};
            int result = 0;
            for (int val: Numeric)
                result ^= val;
            std::cout << result << std::endl;
        }
        {
            int Numeric[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 33, 1, 2, 3, 4, 5, 6, 7, 8, 9, 33, 1, 2, 3, 4, 5, 6, 7, 8, 9, 33, 1, 2, 3,
                             4, 5, 6, 7, 8, 9, 22, 22};
            int result = 0;
            for (int val: Numeric)
                result ^= val;
            std::cout << result << std::endl;
        }
    }

    //--------------------------------------------------------------------------------------//

    template<typename T>
    std::optional<T> __find_first_element_occurred_odd_times(const std::vector<T> &data) {
        std::unordered_map<T, size_t> map;
        for (T val: data)
            map[val]++;

        for (T val: data)
            if (0 != map[val] % 2)
                return val;

        return std::nullopt;
    }

    template<typename T>
    std::optional<T> __find_first_element_occurred_odd_times_set(const std::vector<T> &data) {
        std::unordered_set<T> set;
        for (T val: data) {
            if (auto [iter, inserted] = set.insert(val); false == inserted)
                set.erase(iter);
        }

        for (T val: data) {
            if (set.contains(val))
                return val;
        }

        return std::nullopt;
    }

    template<typename T>
    std::optional<T> __find_first_element_occurred_odd_times_set_one_iter(const std::vector<T> &data) {
        std::optional<T> result;
        std::unordered_set<T> set;
        for (int idx = data.size() - 1; idx >= 0; --idx) {
            if (auto [iter, inserted] = set.insert(data[idx]); false == inserted) {
                set.erase(iter);
                if (result.value() == data[idx])
                    result.reset();
            } else {
                result = data[idx];
            }
        }

        return result;
    }

    void Find_First_Element_Occurred_Once() {
        std::vector<std::pair<std::vector<int>, int>> testData{
                {{1, 2, 3, 2},                         2},
                {{1, 1, 1, 1},                         -1},
                {{1, 2, 1, 2},                         -1},
                {{1, 2, 3, 4, 5, 1, 2, 3, 4, 5},       -1},
                {{1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 4, 5}, 4},
                {{1, 2, 3, 5, 4, 1, 2, 3, 4, 5, 4, 5}, 5},
        };
        for (const auto &[values, resultExpected]: testData) {
            std::cout << values << ". Expected: " << resultExpected << "\n\t"
                      << ' ' << __find_first_element_occurred_odd_times(values).value_or(-1)
                      << ' ' << __find_first_element_occurred_odd_times_set(values).value_or(-1)
                      << ' ' << __find_first_element_occurred_odd_times_set_one_iter(values).value_or(-1)
                      << std::endl;
        }
    }

    //--------------------------------------------------------------------------------------//

    template<typename T>
    std::optional<T> _find_first_repeating_element(const std::vector<T> &data) {
        int minIdx = -1;
        std::unordered_set<T> set;
        for (int idx = data.size() - 1; idx >= 0; --idx) {
            if (!set.insert(data[idx]).second)
                minIdx = idx;
        }
        return -1 == minIdx ? std::nullopt : std::make_optional<int>(data[minIdx]);
    }

    void Find_First_Repeating_Element() {
        std::vector<int> data{10, 5, 3, 4, 3, 5, 6};
        // std::vector<int> data {1,2,3};
        std::optional<int> res = _find_first_repeating_element(data);

        std::cout << res.value_or(-1) << std::endl;
    }


    //---------------------------------------------------------------------------------------//

    int find_minimum_index_of_repeating_element_GOOD(const std::vector<int> &numbers) {
        std::unordered_map<int, int> dup;
        int pos = numbers.size();
        for (size_t i = 0; i < numbers.size(); i++) {
            if (auto result = dup.insert({numbers[i], i}); !result.second)
                pos = std::min(pos, result.first->second);
        }
        return pos == numbers.size() ? -1 : pos;
    }

    long find_minimum_index_of_repeating_element(const std::vector<int> &numbers) {
        std::unordered_set<int> dup{numbers.begin(), numbers.end()};
        long minIndex = -1;
        for (long i = std::ssize(numbers); i >= 0; i--) {
            if (dup.end() != dup.find(numbers[i]))
                minIndex = i;
        }
        return minIndex;
    }

    void Find_Minimum_Index_Of_RepeatingElement() {
        std::vector<int> numbers = {5, 6, 3, 4, 3, 6, 4, 5};
        std::cout << "Result = " << find_minimum_index_of_repeating_element_GOOD(numbers) << std::endl;
        std::cout << "Result = " << find_minimum_index_of_repeating_element(numbers) << std::endl;
    }

    //--------------------------------------------------------------------------------------//

    int binarySearch(const std::vector<int> &numbers,
                     const int left,
                     const int right,
                     const int x) {
        if (right < left)
            return -1;
        const int mid = left + (right - left) / 2;

        if (numbers[mid] == x)
            return mid;
        if (numbers[mid] > x)
            return binarySearch(numbers, left, mid - 1, x);

        return binarySearch(numbers, mid + 1, right, x);
    }

    template<typename T>
    int binary_search(const std::vector<T> &numbers,
                      const T value) {
        size_t left = 0, right = numbers.size() - 1, idxMid = 0;
        while (right > (left + 1)) {
            idxMid = (left + right) / 2;
            if (value == numbers[idxMid])
                return numbers[idxMid];
            if (numbers[idxMid] > value)
                right = idxMid;
            else
                left = idxMid;
        }
        return -1;
    }

    int countOccurrences(const std::vector<int> &numbers,
                         const int x) {
        // const int index = binarySearch(numbers, 0, numbers.size() - 1, x);
        const int index = binary_search(numbers, x);
        if (-1 == index)
            return 0;

        // Count elements on left side.
        int count = 1;
        int left = index - 1;
        while (left >= 0 && numbers[left] == x)
            count++, left--;

        // Count elements on right side.
        int right = index + 1;
        while (right < numbers.size() && numbers[right] == x)
            count++, right++;

        return count;
    }

    // Count number of occurrences (or frequency) in a sorted array

    void Count_Number_tOccurrences_SortedArray()
    {
        const std::vector<int> numbers{1, 2, 2, 2, 2, 3, 4, 7, 8, 8};
        const int result = countOccurrences(numbers, 2);

        std::cout << result << std::endl;
    }

    //--------------------------------------------------------------------------------------//

    size_t __smallest_subarray_with_sum_greater_X(const std::vector<int> &Numeric, const size_t X) {
        size_t min_len = Numeric.size(), sum;
        for (size_t i = 0; i < Numeric.size(); i++) {
            sum = 0;
            for (size_t n = i; n < Numeric.size() && (n - i + 1) < min_len; n++) {
                sum += Numeric[n];
                if (sum > X) {
                    min_len = std::min(min_len, n - i + 1);
                    if (1 == min_len)
                        return 1;
                    break;
                }
            }
        }
        return min_len;
    }

    size_t __smallest_subarray_with_sum_greater_X_2(const std::vector<int> &Numeric, const size_t X) {
        size_t min_len = Numeric.size(), sum = 0;

        // Get first 'mimnimum length' and 'sum' > X
        for (size_t i = 0; i < Numeric.size() && sum <= X; i++) {
            sum += Numeric[i];
            min_len = i + 1;
        }

        // Next we will use 'sliding window' approach to check each window
        // of length == 'mimnimum length' for its sum and if
        // sum of elements if 'window - last element' still > X
        // that we can decrement 'mimnimum length' value.

        size_t end_pos = 0;
        for (size_t i = 1; i <= (Numeric.size() - min_len) && min_len > 1; i++) {
            end_pos = min_len + i - 1;
            sum += Numeric[end_pos] - Numeric[i - 1];

            while ((sum - Numeric[end_pos]) > X) {
                sum -= Numeric[end_pos--];
                min_len--;
            }
        }
        return min_len;
    }

    size_t __smallest_subarray_with_sum_greater_X_3(const std::vector<int> &Numeric, const size_t X) {
        size_t min_len = Numeric.size(), sum = 0;

        // Get first 'mimnimum length' and 'sum' > X
        for (size_t i = 0; i < Numeric.size() && sum <= X; i++) {
            sum += Numeric[i];
            min_len = i + 1;
        }

        // Next we will use 'sliding window' approach to check each window
        // of length == 'mimnimum length' for its sum and if
        // sum of elements if 'window - last element' still > X
        // that we can decrement 'mimnimum length' value.

        for (size_t i = min_len; i < Numeric.size() && min_len > 1; i++) {
            sum += Numeric[i] - Numeric[i - min_len];

            while ((sum - Numeric[i]) > X) {
                sum -= Numeric[i--];
                min_len--;
            }
        }
        return min_len;
    }

    void SmallestSubarrayWithSumGreaterX() {
        std::vector<int> Numeric = {3, 4, 4, 1, 9, 6, 1, 3, 9, 5, 1, 3, 9, 10, 10, 4, 8, 3, 6, 8, 4, 2, 5, 8, 9};
        const int X = 10;

        size_t len = __smallest_subarray_with_sum_greater_X(Numeric, X);
        std::cout << len << std::endl;

        len = __smallest_subarray_with_sum_greater_X_2(Numeric, X);
        std::cout << len << std::endl;

        len = __smallest_subarray_with_sum_greater_X_3(Numeric, X);
        std::cout << len << std::endl;
    }

    //--------------------------------------------------------------------------------------//

    size_t __largest_subarray_with_sum_greater_X(const std::vector<int> &Numeric,
                                                 [[maybe_unused]] const size_t X) {
        size_t min_len = Numeric.size();
        return min_len;
    }

    void LargestSubarrayWithSumGreaterX() {
        std::vector<int> Numeric = {2, -3, 3, 2, 0, -1};
        const int X = 10;

        size_t len = __largest_subarray_with_sum_greater_X(Numeric, X);
        std::cout << len << std::endl;
    }

    //--------------------------------------------------------------------------------------//

    void __count_distinct_pair_diff_K(const std::vector<int> &data, int K) {
        std::unordered_map<int, bool> map;
        auto iter = map.end();
        for (int i: data) {
            if (iter = map.find(i - K); map.end() != iter) {
                if (false == iter->second) {
                    std::cout << "[" << i - K << ", " << i << "]" << std::endl;
                    iter->second = true;
                }
            } else {
                map.emplace(i, false);
            }
        }
    }

    void __count_distinct_pair_diff_K_2(const std::vector<int> &data, int K) {
        std::unordered_set<int> hash;
        std::set<std::pair<int, int>> result;
        for (int value: data) {
            if (hash.end() != hash.find(value - K)) {
                result.insert({value, value - K});
            } else {
                hash.insert(value);
            }
        }
        for (const auto &entry: result)
            std::cout << "[" << entry.first << ", " << entry.second << "]" << std::endl;
    }

    void CountDistinctPairs_WithDifference_K() {
        std::vector<int> v = {8, 12, 16, 4, 0, 20, 8, 8, 8, 8, 4, 4, 8, 4};
        __count_distinct_pair_diff_K(v, 4);
        std::cout << "\nTest2\n" << std::endl;
        __count_distinct_pair_diff_K_2(v, 4);
    }

    //--------------------------------------------------------------------------------------//

    void _GroupElements_ByFirstOccurance_BAD(const std::vector<int> &data) {
        std::unordered_map<int, std::pair<size_t, size_t>> tmp;
        for (size_t pos = 0; pos < data.size(); ++pos) {
            if (auto iter = tmp.insert({data[pos], {pos, 1}}); iter.second == false)
                iter.first->second.second++;
        }

        std::map<size_t, std::pair<size_t, int>> tmp2;
        for (const auto &entry: tmp) {
            tmp2.insert({entry.second.first, {entry.second.second, entry.first}});
        }

        for (const auto &entry: tmp2)
            for (size_t i = 0; i < entry.second.first; i++)
                std::cout << entry.second.second << " ";
        std::cout << std::endl;
    }

    void _rearange_(const std::vector<int> &data) {
        std::unordered_map<int, size_t> freqs;
        for (auto v: data)
            freqs[v]++;
        for (auto v: data) {
            if (auto iter = freqs.find(v); freqs.end() != iter) {
                while (iter->second--)
                    std::cout << iter->first << " ";
                freqs.erase(iter);
            }
        }
    }

    void GroupElements_ByFirstOccurance() {
        {
            std::vector<int> v = {1, 2, 3, 1, 2, 1};
            _GroupElements_ByFirstOccurance_BAD(v);
        }
        {
            std::vector<int> v = {5, 4, 5, 5, 3, 1, 2, 2, 4};
            _GroupElements_ByFirstOccurance_BAD(v);
        }
        {
            std::vector<int> v = {5, 4, 5, 5, 3, 1, 2, 2, 4};
            _rearange_(v);
        }
    }

    //--------------------------------------------------------------------------------------//

    void Greatest_Subarray_AllElements_Greater_K() {
        std::vector<int> Numeric = {8, 12, 16, 4, 14, 7, 23, 8, 23, 12, 23, 12, 6, 2, 14, 4, 83};

        int K = 10;
        size_t length = 0, count = 0;
        for (int v: Numeric) {
            if (K > v)
                count = 0;
            else
                count++;
            length = std::max(length, count);
        }
        std::cout << length << std::endl;
    }


    //--------------------------------------------------------------------------------------//

    void Smallest_Subarray_AllElements_Greater_K() {
        std::vector<int> Numeric = {8, 12, 16, 4, 14, 7, 23, 8, 23, 12, 23, 12, 6, 2, 14, 4, 83};

        int K = 10;
        size_t result = 0;
        for (int v: Numeric) {
            if (v > K) { // check if array element greater then K or not
                result = 1;
                break;
            }
        }
        std::cout << result << std::endl;
    }

    //--------------------------------------------------------------------------------------//

    bool _is_permutation(std::vector<int> &v1, std::vector<int> &v2) {
        if (v1.size() != v2.size())
            return false;
        std::unordered_set<int> set(v1.begin(), v2.end());
        for (int val: v2)
            if (1 != set.erase(val))
                return false;
        return true;
    }

    bool _is_permutation_good(std::vector<int> &v1, std::vector<int> &v2) {
        if (v1.size() != v2.size())
            return false;
        std::unordered_map<int, unsigned int> temp;
        std::for_each(v1.cbegin(), v1.cend(), [&temp](auto v) { temp[v]++; });
        return std::all_of(v2.cbegin(), v2.cend(), [&temp](auto v) { return (temp[v]--) > 0; });
    }

    void IsPermutation()
    {
        // std::cout << __FUNCTION__ << std::endl;

        std::vector<int> v1 = {1, 2, 3, 4, 5}, v2 = {3, 4, 1, 2, 5}, v3 = {5, 5, 5, 5, 5};

        std::cout << std::boolalpha << _is_permutation(v1, v2) << "   " << _is_permutation_good(v1, v2) << std::endl;
        std::cout << std::boolalpha << _is_permutation(v1, v3) << "   " << _is_permutation_good(v1, v3) << std::endl;
    }

    //----------------------------------------------------------------------------------------//

    bool _are_reversed_equal(std::vector<int> &v1, std::vector<int> &v2) {
        if (v1.size() != v2.size())
            return false;
        size_t start = 0, end = v2.size() - 1;

        /* Get first from START different element: */
        for (start = 0; start < v2.size() && v1[start] == v2[start]; start++) {}
        if ((v1.size() - 1) == start)
            return true;
        /* Get first from END different element: */
        for (end = v2.size() - 1; end >= start && v1[end] == v2[end]; end--) {}

        /* Check if */
        for (size_t pos = start, i = 0; pos <= end; pos++, i++) {
            if (v1[pos] != v2[end - i])
                return false;
        }
        return true;
    }


    void ReverseToMakeEqual() {
        {
            std::vector<int> v1 = {1, 3, 6, 2, 4}, v2 = {1, 2, 6, 3, 4};
            std::cout << std::boolalpha << _are_reversed_equal(v1, v2) << std::endl;
        }
        {
            std::vector<int> v1 = {1, 5, 6, 7, 4}, v2 = {1, 7, 6, 5, 4};
            std::cout << std::boolalpha << _are_reversed_equal(v1, v2) << std::endl;
        }
    }

    //-----------------------------------------------------------------------------//

    void Missmatch_Sorted_Vectors() {
        const std::vector<int> vect1 = {4, 6, 8, 9};
        const std::vector<int> vect2 = {2, 3, 4, 7, 8, 123, 34};
        std::vector<int> result;

        size_t pos = 0;
        for (int v: vect1) {
            while (vect2.size() > pos) {
                if (vect2[pos] == v) {
                    break;
                } else if (vect2[pos] > v) {
                    result.push_back(v);
                    break;
                }
                pos++;
            }
            if (vect2.size() <= pos) {
                result.push_back(v);
            }
        }

        for (int v: result)
            std::cout << v << std::endl;
        std::cout << std::endl;
    }

    //----------------------------------------------------------------------------------------//

    template<class Iter>
    void __Missmatch(Iter begin1,
                     Iter end1,
                     Iter begin2,
                     [[maybe_unused]] Iter end2) {
        while ((begin1 != end1) && (*begin1 == *begin2)) {
            ++begin1;
            ++begin2;
        }
        std::cout << *begin1 << "   " << *begin2 << std::endl;
    }

    template<class InputIterator1, class InputIterator2>
    void __Missmatch_STD(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2) {
        while ((first1 != last1) && (*first1 == *first2))  // or: pred(*first1,*first2), for version 2
        {
            ++first1;
            ++first2;
        }
        std::cout << *first1 << "   " << *first2 << std::endl;
    }

    template<class Iter>
    void __Missmatch2(Iter begin1, Iter end1, Iter begin2, Iter end2) {
        while (begin1 != end1 && begin2 != end2 && *begin1 == *begin2) {
            ++begin1;
            ++begin2;
        }
        std::cout << *begin1 << "   " << *begin2 << std::endl;
    }

    void Missmatch_Tests() {
        {
            std::vector<int> vect1 = {1, 2, 3, 6, 5};
            std::vector<int> vect2 = {1, 2, 3, 4, 5};

            __Missmatch(vect1.begin(), vect1.end(), vect2.begin(), vect2.end());
            __Missmatch_STD(vect1.begin(), vect1.end(), vect2.begin());
        }

        {
            std::vector<int> vect1 = {1, 2, 3};
            std::vector<int> vect2 = {1, 2, 3, 110, 5};

            __Missmatch2(vect1.begin(), vect1.end(), vect2.begin(), vect2.end());
        }
    }

    //----------------------------------------------------------------------------------------//

    bool _is_reversed_equals(const std::vector<int> &v1, const std::vector<int> &v2) {
        if (v1.size() != v2.size())
            return false;
        //std::vector<int>::const_iterator iter2 = v2.end() - 1;  // and --iter2 in FOR loop
        std::vector<int>::const_reverse_iterator iter2 = v2.rbegin();
        for (std::vector<int>::const_iterator iter1 = v1.begin(); v1.end() != iter1; ++iter1, ++iter2) {
            if (*iter1 != *iter2)
                return false;
        }
        return true;
    }

    bool _is_reversed_equals_2(const std::vector<int> &v1, const std::vector<int> &v2) {
        const int size = static_cast<int>(v1.size());
        if (size != static_cast<int>(v2.size()))
            return false;

        for (int left = 0, right = size - 1; left < size; ++left, --right) {
            if (v1[left] != v2[right])
                return false;
        }

        return true;
    }

    void IsReversedEquals() {
        for (const VectorPair<int> &data: std::vector<VectorPair<int>>{
                {{1, 2, 3},                   {3, 2, 1}},
                {{1, 2, 3},                   {3, 2, 2}},
                {{1, 2, 3, 4, 5, 6, 7, 8, 9}, {9, 8, 7, 6, 4, 4, 3, 2, 1}}
        }) {
            std::cout << std::boolalpha
                      << _is_reversed_equals(data.first, data.second) << ' '
                      << _is_reversed_equals_2(data.first, data.second) << ' '
                      << std::equal(data.first.begin(), data.first.end(), data.second.rbegin()) << std::endl;
        }
    }

    //---------------------------------------------------------------------------//

    std::pair<bool, std::pair<size_t, size_t>> _Subarray_With_Given_Sum(const std::vector<int> &data, const int K) {
        std::unordered_map<size_t, size_t> map;
        int curr_sum = 0;

        for (size_t index = 0; index < data.size(); index++) {
            curr_sum += data[index];

            if (curr_sum == K)
                return {true, {0, index}};
            else if (auto iter = map.find(curr_sum - K); iter != map.end()) {
                return {true, {iter->second + 1, index}};
            }

            map[curr_sum] = index;
        }
        return {false, {-1, -1}};
    }

    std::pair<bool, std::pair<size_t, size_t>> _Subarray_With_Given_Sum2(const std::vector<int> &data, const int K) {
        std::unordered_multimap<int, size_t> map;
        int curr_sum = 0;

        for (size_t index = 0; index < data.size(); index++) {
            curr_sum += data[index];
            if (curr_sum == K)
                return {true, {0, index}};
            else if (auto iter = map.find(curr_sum - K); iter != map.end())
                return {true, {iter->second + 1, index}};

            map.insert({curr_sum, index});
        }
        return {false, {-1, -1}};
    }


    void _Subarray_With_Given_Sum_All(const std::vector<int> &data, const int K) {
        std::unordered_multimap<int, size_t> map;
        int curr_sum = 0;

        for (size_t index = 0; index < data.size(); index++) {
            curr_sum += data[index];
            if (curr_sum == K)
                print_vector(data, 0, index);
            else if (auto iter = map.find(curr_sum - K); iter != map.end()) {
                while (iter != map.end() && iter->first == (curr_sum - K)) {
                    std::cout << "Subarray:    ";
                    print_vector(data, iter->second + 1, index);
                    iter++;
                }
            }
            map.insert({curr_sum, index});
        }
    }

    //---------------------------------------------------------------------------//

    void Find_SubArrays_WithGivenSum() {
        {
            // std::pair<std::vector<int>, int> data { std::vector<int>{2,3,4,5,6,7}, 11};
            const std::pair<std::vector<int>, int> data{std::vector<int>{1, 4, 20, 3, 10, 5, 11}, 33};

            auto [success, borders] = _Subarray_With_Given_Sum(data.first, data.second);
            if (success) {
                print_vector(data.first, borders.first, borders.second);
            }
        }

        /*
        {
            std::vector<int> Numeric = { 9, -5, 13, 2, -7, 10, -3 };
            int X = 10;

            auto [success, borders] = _Subarray_With_Given_Sum2(Numeric, X);
            if (success) {
                print_vector(Numeric, borders.first, borders.second);
            }
        }
        {
            int X = 10;
            std::vector<int> Numeric = { 9, -5, 13, 2, -7, 10, -3 };
            _Subarray_With_Given_Sum_All(Numeric, X);
        }
        */
    }

    //--------------------------------------------------------------------------------------//

    void _find_subArrays_sum_zero_SLOW(const std::vector<int> &Numeric) {
        for (size_t i = 0; i < Numeric.size(); i++) {
            for (size_t n = i, sum = 0; n < Numeric.size(); n++) {
                sum += Numeric[n];
                if (0 == sum) {
                    std::cout << "Subarray [" << i << ".." << n << "]" << std::endl;
                }
            }
        }
    }

    void _find_subArrays_sum_zero(const std::vector<int> &Numeric) {
        std::unordered_multimap<int, int> map = {{0, -1}};
        for (size_t i = 0, sum = 0; i < Numeric.size(); i++) {
            sum += Numeric[i];

            // As soon as we meet sum in the map, it means that there is at least one subarray with
            // the sum 0. And the beginning of this list (lists) has a second index in the map
            if (auto iter = map.find(sum); map.end() != iter) {
                while (iter != map.end() && iter->first == static_cast<int>(sum)) {
                    std::cout << "Subarray [" << iter->second + 1 << ".." << i << "]" << std::endl;
                    iter++;
                }
            }
            map.insert({sum, i});
        }
    }

    void Find_SubArrays_SumZero() {
        // const std::vector<int> Numeric = { 3,4,-7,3,1,3,1,-4,-2,-2};
        const std::vector<int> Numeric = {1, 3, 2, -5, 3};
        _find_subArrays_sum_zero(Numeric);
        std::cout << std::endl;
        _find_subArrays_sum_zero_SLOW(Numeric);
    }

    //----------------------------------------------------------------------------------------------------------

    void findCommon(const std::vector<int> &ar1,
                    const std::vector<int> &ar2,
                    const std::vector<int> &ar3) {
        for (size_t i = 0, j = 0, k = 0; i < ar1.size() && j < ar2.size() && k < ar3.size(); /** **/) {
            if (ar1[i] == ar2[j] && ar2[j] == ar3[k]) { // If x = y and y = z, print any of them and move ahead in all arrays
                std::cout << ar1[i] << " ";
                ++i;
                ++j;
                ++k;
            } else if (ar1[i] < ar2[j])  // x < y
                i++;
            else if (ar2[j] < ar3[k])  // y < z
                j++;
            else                       // We reach here when x > y and z < y, i.e., z is smallest
                k++;
        }
    }

    // Find common elements in three sorted arrays
    void FindCommonElements_3_SortedArrays() {
        std::vector<int> array1{1, 5, 10, 20, 40, 80},
                array2{6, 7, 20, 80, 100},
                array3{3, 4, 15, 20, 30, 70, 80, 120};

        std::cout << "Common Elements are ";
        findCommon(array1, array2, array3);
    }

    //---------------------------------------------------------------------------//

    // You are given an array arr of N integers.For each index i, you are required to determine
    // the number of contiguous subarrays that fulfills the following conditions :
    // The value at index i must be the maximum element in the contiguous subarrays, and
    // These contiguous subarrays must either start from or end on index i.
    // arr = [3, 4, 1, 6, 2] ----> [1, 3, 1, 5, 1]
    void Subarrays_WithCurrentMaxElement() {
        std::vector<int> Numeric = {3, 4, 1, 6, 2};
        for (size_t i = 0; i < Numeric.size(); i++) {
            int count = -1;
            for (int n = i; n >= 0 && Numeric[i] >= Numeric[n]; n--, count++) {}
            for (int n = i; n < static_cast<int>(Numeric.size()) && Numeric[i] >= Numeric[n]; n++, count++) {}
            std::cout << count << std::endl;
        }
        std::cout << "Done" << std::endl;
    }
}

namespace Numeric
{
    struct Stats final
    {
        int count{0};
        int start{0};
        int end{0};

        explicit Stats(int start = 0) : start{start} {}
    };

    int degreeOfArray(const std::vector<int>& values)
    {
        int maxOccurred = 0;
        std::unordered_map<int, Stats> counter{};
        for (int idx = 0; idx < values.size(); ++idx) {
            const auto [iter, ok] = counter.emplace(values[idx], idx);
            ++(iter->second.count);
            iter->second.end = idx;
            maxOccurred = std::max(maxOccurred, iter->second.count);
        }

        int minLength = values.size();
        for (const auto &[key, stats]: counter) {
            if (stats.count == maxOccurred)
                minLength = std::min(minLength, stats.end - stats.start + 1);
        }

        return minLength;
    }

    /**  Degree of an Array
     *
     * Given a non-empty array of non-negative integers nums, the degree of this array is defined
     * as the maximum frequency of any one of its elements.
     * Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.
     *
     * Explanation:
     *   The input array has a degree of 2 because both elements 1 and 2 appear twice.
     *   Of the subarrays that have the same degree:  [1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
     *   The shortest length is 2. So return 2.
     *
     *  Explanation:
     *    The degree is 3 because the element 2 is repeated 3 times.
     *    So [2,2,3,1,4,2] is the shortest subarray, therefore returning 6.
    */
    void Min_Length_SubArray_WithSameDegree()
    {
        for (const std::vector<int> &input: std::vector<std::vector<int>>{
                {1, 2, 2, 3, 1}, // -> 2
                {2, 2, 3, 1, 4, 2}, // -> 6
                {2, 1, 1, 2, 1, 3, 3, 3, 1, 3, 1, 3, 2} // -> 7
        }) {
            const auto result = degreeOfArray(input);
            std::cout << "Result = " << result << std::endl;
        }
    }
}

namespace Numeric
{
    std::vector<int> _top_K_Frequent(const std::vector<int>& nums, int k)
    {
        std::unordered_map<int, int> counter;
        for (int v: nums)
            ++counter[v];

        std::map<int, std::vector<int>> freqs;
        for (const auto [val, N]: counter)
            freqs[N].emplace_back(val);

        std::vector<int> out;
        out.reserve(k);
        for (auto iter = freqs.rbegin(); freqs.rend() != iter; ++iter) {
            std::sort(iter->second.begin(), iter->second.end());
            for (auto &&s: iter->second) {
                out.push_back(s);
                if (--k == 0)
                    return out;
            }
        }
        return out;
    }

    void Find_Top_K_Frequent_Numbers()
    {
        for (const std::pair<std::vector<int>, int>& data: std::vector<std::pair<std::vector<int>, int>> {
                {{1,1,1,2,2,3}, 2} // ==> { 1,2 }
        })
        {
            std::cout << _top_K_Frequent(data.first, data.second) << std::endl;
        }
    }
}

namespace Numeric
{
    bool canJump(const std::vector<int>& nums) {
        size_t step = 0;
        for (size_t idx = 0; idx < nums.size(); ++idx) {
            // std::cout << "idx: " << idx << ", step: " << step << std::endl;
            if (step >= idx) {
                step = std::max(idx + nums[idx], step);
            } else
                break;
        }
        return step > nums.size();
    };


    // Given an array of non-negative integers, you are initially positioned at the first index of the array.
    // Each element in the array represents your maximum jump length at that position.
    // Determine if you are able to reach the last index.
    // Input: [2,3,1,1,4] --> True, [3,2,1,0,4] --> False
    void CanJump() {
        // std::vector<int> vect {2,1,2,0,4};
        std::vector<int> vect {3,0,3,0,4};

        std::cout << std::boolalpha << canJump(vect) << std::endl;
    }

    //---------------------------------------------------------------------------------------

    // [1,2,3,1]   -> 1 + 3 = 4
    // [2,7,9,3,1] -> 2 + 9 + 1 = 12
    int MaxSum_of_NonConsecutive_Elements(std::vector<int> nums) {
        if (nums.size() >= 2)
            nums[1] = std::max(nums[0], nums[1]);
        for (size_t i = 2; i < nums.size(); ++i)
            nums[i] = std::max(nums[i - 1], nums[i - 2] + nums[i]);
        return !nums.empty() ? nums.back() : 0;
    }


    void MaxSum_of_NonConsecutive_Elements_In_Array() {
        std::cout << MaxSum_of_NonConsecutive_Elements({1,2,3,1}) << std::endl;
        std::cout << MaxSum_of_NonConsecutive_Elements({2,7,9,3,1}) << std::endl;
    }
};

namespace Numeric::Random
{
    unsigned int flipCoin(float p)
    {
        const static int ones = static_cast<int>(p * 100) % 100;
        static std::vector<int> data;

        if (data.empty()) {
            data.resize(100);
            std::fill_n(data.begin(), ones, 1);
            std::random_shuffle ( data.begin(), data.end() );
        }

        int value = data.back();
        data.pop_back();
        return value;
    }

    unsigned int flipCoin2(float p) {
        return float(rand()) / RAND_MAX < p ? 1 : 0;
    }

    //  Using the C++ random number generator rand(),
    //  implement a biased coin that outputs 1 with probability p and 0 with probability 1–p
    void BiasedCoin() {
        constexpr size_t count = 100;
        constexpr double ratio_expected = 0.65;

        {
            double sum = 0;
            for (size_t i = 0; i < count; i++)
                sum += flipCoin(ratio_expected);
            std::cout << "Expected ratio = " << ratio_expected << ". Actual = " << sum / count << std::endl;
        }

        {
            double sum = 0;
            for (size_t i = 0; i < count; i++)
                sum += flipCoin2(ratio_expected);
            std::cout << "Expected ratio = " << ratio_expected << ". Actual = " << sum / count << std::endl;
        }
    }
}

namespace Numeric::Intervals
{
    /*
    Let X be a set of n intervals on the real line.
    We say that a set of points P "stabs" X if every interval in X contains at least one point in P.
    Compute the smallest set of points that stabs X.
    For example, given the intervals [(1, 4), (4, 5), (7, 9), (9, 12)], you should return [4, 9].
    */
    void Find_Union_Interval()
    {
        const std::vector<std::pair<int, int>> intervals{
                {1,  4},
                {3,  7},
                {7,  9},
                {11, 27}
        };

        int a{11110}, b{0};
        for (size_t i = 1; i < intervals.size(); ++i) {
            int x = std::max(intervals[i - 1].second, intervals[i].first);
            a = std::min(a, x);
            b = std::max(b, x);
        }

        std::cout << a << ", " << b << std::endl;
    }

    /**----------------------------------------------------------------------------------------------**/

    void calc_max_hotel_visitors(const std::vector<std::pair<int, int>>& intervals)
    {
        int maxVisitors = 0;
        std::unordered_map<int, int> tmp {};
        for (const auto& [checkIn, checkOut]: intervals) {
            for (auto day = checkIn; day <= checkOut; ++day) {
                maxVisitors = std::max(maxVisitors, ++tmp[day]);
            }
        }

        std::cout << "Max visitors: " << maxVisitors << std::endl;
    }

    // Посетители заселяюстя в отель, какое-то время там живут и выезжают
    // Запись об этом выглядит как [день заселения, день выезда]
    // Нужно посчитать максимальное количество посетителей проживших в отеле в один и тот же момент времени

    void CalcMaxHotelVisitors()
    {
        const std::vector<std::pair<int, int>> checkIns {
            {1, 2},
            {1, 2}
        };

        calc_max_hotel_visitors(checkIns);
    }
}

namespace Numeric
{
    std::vector<int> sortedSquaredArray(const std::vector<int>& numbers)
    {
        int right = 0;
        while (0 > numbers[right]) {
            ++right;
        }

        std::vector<int> result;
        result.reserve(numbers.size());

        const int size = numbers.size();
        int left = right - 1;
        while (left >= 0 && size > right)
        {
            const int leftVal = std::pow(numbers[left], 2), rightVal = std::pow(numbers[right], 2);
            if (leftVal > rightVal) {
                result.push_back(rightVal);
                ++right;
            } else {
                result.push_back(leftVal);
                --left;
            }
        }

        while (left >= 0)
            result.push_back(std::pow(numbers[left--], 2));
        while (size > right)
            result.push_back(std::pow(numbers[right++], 2));

        return result;
    }


    void printSortedSquaredNumber_InSortedArray()
    {

        std::vector<int> testData {-4, -3, -2, 0 ,1 ,5, 6, 9};
        std::vector<int> result = sortedSquaredArray(testData);

        for (int i: result)
            std::cout << i <<  ' ';
        std::cout << std::endl;
    }
}

namespace Numeric
{
    /** Problem:
    Given an array of integers as std::vector<int>, return
    the majority element (guaranteed to be present).

    A majority element has more than size/2 number of instances in the array.

    There is a solution that runs in O(n) time and O(1) space.
    **/

    int majority_element(const std::vector<int>& nums)
    {
        int major = 0;
        for (size_t count = 0; auto v : nums) {
            if (0 == count) {
                major = v;
                count = 1;
            } else if (v == major) {
                ++count;
            } else {
                --count;
            }
        }
        return major;
    }

    void Find_The_Majority_Element()
    {
        for (const std::vector<int>& v: std::vector<std::vector<int>> {
                // {0},
                // {1,1,1,2},
                {2,2,1,1,1},
                // {1,0,1,2,1,3,1,5},
                // {1,2,3,4,5,6,6,6,6,6,6,6},
        })
        {
            const int major = majority_element(v);
            std::cout << "[ " << v << "] ==> " << major << std::endl;
        }
    }
}

namespace Numeric::Boundaries
{
    size_t max_area(const std::vector<long> &height)
    {
        size_t max = 0;
        for (size_t left = 0, right = height.size() - 1, area = 0; left != right;)
        {
            area = std::min(height[left], height[right]) * (right - left);
            max = std::max(max, area);
            if (height[left] <= height[right])
                ++left;
            else
                --right;
        }
        return max;
    }

    long max_area_iter(const std::vector<long> &height)
    {
        auto left = height.begin();
        auto right = std::prev(height.end());
        long max = 0;
        while (left != right) {
            max = std::max(max, std::min(*left, *right) * (right - left));
            if (*left <= *right)
                ++left;
            else
                --right;
        }
        return max;
    }

    /**
     * Problem
     * Given information about the height of a boundary at each position as std::vector<int64_t>,
     * determine the maximum area formed between any two boundaries.
     * The area is the minimum height of the two boundaries multiplied by the distance.
     *
     * Solution:
     * If we switch one of the boundaries, we are decreasing the distance, so the only way to improve
     * the area is to switch the lower of the two boundaries.
     * Switching the higher one decreases the distance without improving the height
     * (because the height is dictated by the lower of the two boundaries).
     * Therefore, to get the maximum, we can repeatedly apply this logic, keeping track of the maximum area as we go.
    **/

    void Maximum_Area_Between_Boundaries()
    {
        for (const auto &[heights, area_expected]: std::vector<std::pair<std::vector<long>, long>>{
                {{1, 1},                               1},
                {{1, 9, 1},                            2},
                {{1, 3, 3,  1},                        3},
                {{1, 3, 1,  3,  1},                    6},
                {{1, 3, 8,  10, 3, 1},                 9},
                {{1, 3, 8,  8,  3, 1},                 9},
                {{1, 3, 10, 10, 3, 1},                 10},
                {{1, 8, 6,  2,  5, 4,  8 ,3, 7},       49},
                {{1, 2, 5,  3,  2, 12, 1, 3, 7, 8, 2}, 35}
        }) {
            std::cout << max_area(heights) << " " << max_area_iter(heights)
                      << ", Expected: " << area_expected << std::endl;
        }
    }
}

namespace Numeric
{
    uint32_t find_rank(const std::vector<uint32_t>& papers)
    {
        std::map<uint32_t, uint32_t> tmp;
        for (uint64_t v: papers)
            ++tmp[v];

        uint32_t result = 0, count = 0;
        for (auto & [rank, ref_count] : std::ranges::reverse_view(tmp))
        {
            count += ref_count;
            if (count >= rank)
                result  = std::max(result, rank);
        }

        return result;
    }

    // Scientists are publishing papers, and these papers are getting cited in other papers.
    // Find the rank of the scientist.
    // Rank: largest R, such that at least R papers have >= R citations

    // std::vector<uint32_t> papers {3, 4, 5, 11}; ->  3
    // std::vector<uint32_t> papers {2, 4, 11};   ->  2

    /**
    Идея в том что бы структуры в виде вектора статей с количеством цитат (при ходит на вход)
    создать структуру данных (map)
    {
        [количество цитат] <--> [количество таких статей в векторе]
    }
    А далее итерируясь в обратном порядке
    подсчитывать значения в map-e --> считая колчество статей с данным и большым количеством цитат
    (что соответствует значению в map-e)
     */

    void Rank()
    {
        std::vector<uint32_t> papers {3, 4, 5, 11};

        uint32_t result = find_rank(papers);

        std::cout << result << std::endl;
    }
}

namespace Numeric
{
    double median_of_two_sorted_arrays(const std::vector<int>& nums1,
                                       const std::vector<int>& nums2)
    {
        const int size1 = std::ssize(nums1), size2 = std::ssize(nums2);
        const int steps = (size1 + size2) / 2;
        int m1 = 0, m2 = 0;
        for (int n = 0, idx1 = 0, idx2 = 0; n <= steps; ++n)
        {
            m1 = m2;
            if (size1 > idx1 && size2 > idx2)
                m2 = nums1[idx1] > nums2[idx2] ? nums2[idx2++] : nums1[idx1++];
            else
                m2 = size1 > idx1 ? nums1[idx1++] : nums2[idx2++];
        }

        return (size1 + size2) % 2 == 1 ? static_cast<double>(m2) : static_cast<double>(m1 + m2) / 2;
    }

    /**
    Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
    The overall run time complexity should be O(log (m+n)).

    Example 1:    Input: nums1 = [1,3], nums2 = [2]  --> Result: 2.00000
                  Explanation: merged array = [1,2,3] and median is 2.

    Example 2:    Input: nums1 = [1,2], nums2 = [3,4] --> Result: 2.50000
                  Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
    */
    void Median_of_Two_Sorted_Arrays()
    {
        std::cout << median_of_two_sorted_arrays({1,3}, {2}) << std::endl;
        std::cout << median_of_two_sorted_arrays({1,2}, {3,4}) << std::endl;
    }
}

namespace Numeric
{
    int single_number(const std::vector<int>& nums)
    {
        int singleNum = 0;
        for (int num : nums) {
            singleNum ^= num;
        }
        return singleNum;
    }

    /**
    Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
    You must implement a solution with a linear runtime complexity and use only constant extra space.

    Example 1: Input: nums = [2,2,1] |  Example 2:    Input: nums = [4,1,2,1,2]  |  Example 3:  Input: nums = [1]
               Output: 1             |                Output: 4                  |              Output: 1
    */
    void Single_Number()
    {
        for (const std::pair<std::vector<int>, int>& data:  std::vector<std::pair<std::vector<int>, int>>{
                {{2, 2, 1}, 1}, {{4,1,2,1,2}, 4}, {{1}, 1}
        })
        {
            std::cout << single_number(data.first) << std::endl;
        }
    }
}

namespace Numeric
{
    void rotate_array(std::vector<int>& nums, uint32_t k)
    {
        std::vector<int> result (nums.size(), 0);
        for (int i = 0, size = nums.size(); i < size; ++i)
            result[(k + i) % size] = nums[i];
        std::swap(nums, result);
    }

    void rotate_array_ex(std::vector<int>& nums, uint32_t k)
    {
        k = k % nums.size();
        if (nums.size() < 2 || 0 == k || k >= nums.size())
            return;
        std::vector<int> head (nums.end() - k, nums.end());
        for (uint32_t idx = nums.size() - 1; idx >= k; --idx)
            nums[idx] = nums[idx - k];
        for (uint32_t idx = 0; idx < k; ++idx)
            nums[idx] = head[idx];
    }

    void Rotate_Array()
    {
        std::vector<int> values {1, 2};
        std::cout << values << " ==> ";

        rotate_array_ex(values, 1);

        std::cout << values << std::endl;
    }
}

namespace Numeric::Backtracking
{
    void backtrack(size_t start,
                   std::vector<int> subset,
                   const std::vector<int>& input,
                   std::vector<std::vector<int>>& result)
    {
        result.push_back(subset);
        for (size_t idx = start; idx < input.size(); idx++)
        {
            if (idx != start && input[idx] == input[idx - 1])
                continue;
            subset.push_back(input[idx]);
            backtrack(idx + 1, subset, input, result);
            subset.pop_back();
        }
    }

    std::vector<std::vector<int>> subsets(std::vector<int>& input)
    {
        std::vector<std::vector<int>> result;
        std::sort(input.begin(), input.end());
        backtrack(0, {}, input,  result);
        return result;
    }



    /** Given an integer array nums of unique elements, return all possible subsets
        The solution set must not contain duplicate subsets. Return the solution in any order.
        Input: nums = [1,2,3] Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
        Input: nums = [0]     Output: [[],[0]
    **/
    void List_Of_Unique_Subsets()
    {
        std::vector<int> input {1, 2 ,3};
        const std::vector<std::vector<int>> result = subsets(input);

        for (const auto& sub_set: result) {
            std::cout << "[" << sub_set << " ]\n";
        }
    }
}


namespace Numeric::Backtracking
{
    std::vector<std::vector<int>> permuteUnique(std::vector<int>& input)
    {
        int n = input.size();
        if (n <= 1)
            return { input };
        std::set<std::vector<int>> permuted, sret;
        for (int i = 0; i < n; ++i)
        {
            int cur = input[i];
            std::swap(input[i], input[n - 1]);
            input.pop_back();
            if (permuted.count(input) > 0) {
                input.push_back(cur);
                std::swap(input[i], input[n - 1]);
                continue;
            }
            permuted.insert(input);
            std::vector<std::vector<int>> sub = permuteUnique(input);
            for (auto& s : sub) {
                s.push_back(cur);
                sret.insert(s);
            }
            input.push_back(cur);
            std::swap(input[i], input[n - 1]);
        }
        std::vector<std::vector<int>> ret(sret.begin(), sret.end());
        return ret;
    }


    /** Given a collection of numbers that might contain duplicates, return all possible unique permutations.
        Input: [1,1,2]  Output: [1,1,2], [1,2,1], [2,1,1]
    **/
    void Permutations()
    {
        std::vector<int> input {1, 1 ,2};
        const std::vector<std::vector<int>> result = permuteUnique(input);


        for (const auto& sub_set: result) {
            std::cout << "[" << sub_set << " ]\n";
        }
    }
}


void ArraysAlgorithms::Other()
{
    // Numeric::isPowerOf2();

    // Numeric::Rotate_Array();

    // Numeric::GreatestCommonDivisor();
    // Numeric::LeastCommonMultiple();
    // Numeric::LongestCommonSubsequence();
    // Numeric::FinabochiNumeric();
    // Numeric::LongestSubset_FinabochiNumeric();
    // Numeric::CountAndSaySequence_Generate();
    // Numeric::CountAndSaySequence_Get_Kth_Token();
    // Numeric::CountOrderedPairs();
    // Numeric::ReverseNumber();
    // Numeric::IsPalindrome();
    // Numeric::GetNumberOfDigit();
    // Numeric::RearangeArray();
    // Numeric::FindSmallestWithoutRecursion();
    // Numeric::Devide_WithDevisionOperator();
    // Numeric::ComputeNumberOfDivisiblsInRange();
    // Numeric::Largest_Triple_Products();
    // Numeric::BillionUsers();
    // Numeric::BalancedSplit();
    // Numeric::Kadane();
    // Numeric::MaximumSumSubarray_Kadane();
    // Numeric::GetAllSubsequentSubArrays();
    // Numeric::GetAllSubArrays_NonSequenced();
    // Numeric::CheckIsPrime();
    // Numeric::CoinsChangeProblem();
    // Numeric::DeviceNumeric_WithOut_Operator();
    // Numeric::LeadNumber_Window_IgnoreNulls();
    // Numeric::AnalogClockAngles();
    // Numeric::Sqrt();

    // Numeric::FindMinMax();
    // Numeric::FindTwoSmallestElements();
    // Numeric::Find_N_Min_Elements();
    // Numeric::Find_N_Min_Elements_2();
    // Numeric::Find_N_Max_Elements();
    // Numeric::Find_N_Max_Elements2();
    // Numeric::MaxPairSumInArray();

    // Numeric::NextLargerElement();
    // Numeric::Find_All_Distinct_Combinations_LengthK();

    // Numeric::Find_Longest_Increasing_Subsequence();
    // Numeric::Find_Longest_Increasing_Subsequence_1();
    // Numeric::Longest_Consecutive_Sequence();
    // Numeric::FindLongestSubArray();
    // Numeric::FindLongestSubArray_K_UniqueElements();
    // Numeric::Find_SubArrays_SumZero();
    // Numeric::Find_SubArrays_WithGivenSum();
    // Numeric::SmallestSubarrayWithSumGreaterX();
    // Numeric::LargestSubarrayWithSumGreaterX();   /**  UNIMPLEMENTED  **/
    // Numeric::Greatest_Subarray_AllElements_Greater_K();
    // Numeric::Smallest_Subarray_AllElements_Greater_K();
    // Numeric::Subarrays_WithCurrentMaxElement();


    // Numeric::SplitArrayToPieces_FindNumber_ByExample();
    // Numeric::Sum_Of_ConsecutiveNumeric();
    // Numeric::Is_Array_Elements_Consecutive();
    // Numeric::MiniMaxSum_Of4();
    // Numeric::Find_Sum_All_Numeric();
    // Numeric::Find_Multiplier_Pair();
    // Numeric::Find_Multiplier_Pair2();
    // Numeric::Find_Pair_SumX_Sorted();
    // Numeric::Find_3_Elements_SumX_Unsorted();
    // Numeric::Find_DifferentPairs_SumK();
    // Numeric::Find_3_Elements_SumX_Sorted();

    // Numeric::RemoveElement();
    // Numeric::RemoveDuplicates();
    // Numeric::Contains_Duplicate();
    // Numeric::RemoveDuplicates_SortedArray();
    // Numeric::DeleteFromArray();

    // Numeric::Find_The_Majority_Element();

    // Backtracking::List_Of_Unique_Subsets();
    // Backtracking::Permutations();


    // Numeric::FindCommonElements_3_SortedArrays();

    // Numeric::FindTheMissingNumber_SortedArray();
    // Numeric::FindTheMissingNumber_Unsorted();
    // Numeric::FindTheMissingNumber_Unsorted_AnyRange();
    // Numeric::MissingNumber();
    // Numeric::Find_K_MissingNumber_Sorted();
    // Numeric::Find_K_MissingNumber();

    // Numeric::Find_Smallest_Missing_Positive_Number();
    // Numeric::Find_Repeating_And_Missing();
    // Numeric::FindTheDuplicateValue();

    // Numeric::printSortedSquaredNumber_InSortedArray();

    // Numeric::Find_All_Symmetric_Pairs_InArray();

    // Numeric::Find_Elements_Occured_Once();
    // Numeric::Find_ONE_Element_Occured_Once();
    // Numeric::Find_First_Element_Occurred_Once();
    // Numeric::Find_First_Repeating_Element();
    // Numeric::Find_Minimum_Index_Of_RepeatingElement();

    // Numeric::Find_Top_K_Frequent_Numbers();

    // Numeric::Count_Number_tOccurrences_SortedArray();

    // Numeric::CountDistinctPairs_WithDifference_K();
    // Numeric::GroupElements_ByFirstOccurance();

    // Numeric::Add_One_To_Integer_ArrayTest();
    // Numeric::Product_Of_All_Numeric_Except_N();

    // Numeric::Missmatch_Sorted_Vectors();
    // Numeric::Missmatch_Tests();
    // Numeric::IsPermutation();
    // Numeric::IsReversedEquals();
    // Numeric::ReverseToMakeEqual();
    // Numeric::MaxSum_of_NonConsecutive_Elements_In_Array();

    // Boundaries::Maximum_Area_Between_Boundaries();

    // Numeric::Rank();

    // Random::BiasedCoin();

    // Median_of_Two_Sorted_Arrays();

    // Single_Number();

    /** Degree_Of_Array degreeOfArray: With same occurrences of duplicated elements **/
    // Numeric::Min_Length_SubArray_WithSameDegree();

    // Numeric::CanJump();  // With same occurrences of duplicated elements

    // Intervals::Find_Union_Interval();

    // Intervals::CalcMaxHotelVisitors();
}
