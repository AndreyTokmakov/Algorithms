/**============================================================================
Name        : Find_SubArrays_Sum_Equal_K.cpp
Created on  : 20.01.2025
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

    void find_all_sub_arrays_with_given_sum(const std::vector<int> &data, const int K)
    {
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
}

void ArraysAlgorithms::Find_SubArrays_Sum_Equal_K()
{

}
