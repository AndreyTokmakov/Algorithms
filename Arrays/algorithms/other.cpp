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

    using namespace ArraysAlgorithms;
}


namespace Numeric
{

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
}

namespace Numeric
{
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


void ArraysAlgorithms::Other()
{
    // Numeric::Rotate_Array();
    // Numeric::LongestCommonSubsequence();
    // Numeric::FinabochiNumeric();
    // Numeric::CountAndSaySequence_Generate();
    // Numeric::CountAndSaySequence_Get_Kth_Token();
    // Numeric::CountOrderedPairs();
    // Numeric::RearangeArray();
    // Numeric::FindSmallestWithoutRecursion();
    // Numeric::Devide_WithDevisionOperator();
    // Numeric::ComputeNumberOfDivisiblsInRange();
    // Numeric::Largest_Triple_Products();
    // Numeric::BillionUsers();
    // Numeric::BalancedSplit();
    // Numeric::GetAllSubsequentSubArrays();
    // Numeric::GetAllSubArrays_NonSequenced();
    // Numeric::CoinsChangeProblem();
    // Numeric::DeviceNumeric_WithOut_Operator();
    // Numeric::LeadNumber_Window_IgnoreNulls();
    // Numeric::AnalogClockAngles();
    // Numeric::FindMinMax();
    // Numeric::FindTwoSmallestElements();
    // Numeric::MaxPairSumInArray();
    // Numeric::NextLargerElement();
    // Numeric::Find_All_Distinct_Combinations_LengthK();
    // Numeric::Longest_Consecutive_Sequence();
    // Numeric::FindLongestSubArray();
    // Numeric::FindLongestSubArray_K_UniqueElements();
    // Numeric::Find_SubArrays_SumZero();
    // Numeric::SmallestSubarrayWithSumGreaterX();
    // Numeric::LargestSubarrayWithSumGreaterX();   /**  UNIMPLEMENTED  **/
    // Numeric::Greatest_Subarray_AllElements_Greater_K();
    // Numeric::Smallest_Subarray_AllElements_Greater_K();
    // Numeric::Subarrays_WithCurrentMaxElement();
    // Numeric::SplitArrayToPieces_FindNumber_ByExample();
    // Numeric::Sum_Of_ConsecutiveNumeric();
    // Numeric::MiniMaxSum_Of4();
    // Numeric::Find_3_Elements_SumX_Unsorted();
    // Numeric::Find_3_Elements_SumX_Sorted();
    // Numeric::Find_The_Majority_Element();
    // Backtracking::List_Of_Unique_Subsets();
    // Backtracking::Permutations();
    // Numeric::FindCommonElements_3_SortedArrays();
    // Numeric::Find_K_MissingNumber_Sorted();
    // Numeric::Find_K_MissingNumber();
    // Numeric::Find_Repeating_And_Missing();
    // Numeric::printSortedSquaredNumber_InSortedArray();
    // Numeric::Find_All_Symmetric_Pairs_InArray();
    // Numeric::Find_Elements_Occured_Once();
    // Numeric::Find_ONE_Element_Occured_Once();
    // Numeric::Find_First_Element_Occurred_Once();
    // Numeric::Find_Minimum_Index_Of_RepeatingElement();
    // Numeric::Count_Number_tOccurrences_SortedArray();
    // Numeric::GroupElements_ByFirstOccurance();
    // Numeric::Add_One_To_Integer_ArrayTest();
    // Numeric::Missmatch_Sorted_Vectors();
    // Numeric::Missmatch_Tests();
    // Numeric::IsPermutation();
    // Numeric::MaxSum_of_NonConsecutive_Elements_In_Array();
    // Boundaries::Maximum_Area_Between_Boundaries();
    // Random::BiasedCoin();

    /** Degree_Of_Array degreeOfArray: With same occurrences of duplicated elements **/
    // Numeric::Min_Length_SubArray_WithSameDegree();
    // Intervals::Find_Union_Interval();
    // Intervals::CalcMaxHotelVisitors();
}
