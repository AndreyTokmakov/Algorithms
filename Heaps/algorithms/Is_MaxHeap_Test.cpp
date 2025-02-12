/**============================================================================
Name        : Is_MaxHeap_Test.cpp
Created on  : 11.02.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../HeapsAlgorithms.h"

namespace
{
    using namespace HeapsAlgorithms;

    bool _is_max_heap_good(const std::vector<int>& data)
    {   // index of the parent of the last element ((SIZE - 1) - 1) / 2
        const size_t lastParentIdx = (data.size() - 2) / 2;

        // Check MaxHeap condition expect the 'last parent'. Will be checked at the end
        for (size_t idx = 0; idx < lastParentIdx; ++idx) {
            if (data[idx * 2 + 1] > data[idx] || data[idx * 2 + 2] > data[idx])
                return false;
        }

        if (data[lastParentIdx * 2 + 1] > data[lastParentIdx])
            return false;
        return data.size() <= (lastParentIdx * 2 + 2) || data[lastParentIdx] > data[lastParentIdx * 2 + 2];
    }

    bool Is_MaxHeap(const std::vector<int>& data)
    {
        for (size_t i = 0; i <= (data.size() / 2 - 1); i++) {
            if (data[i * 2 + 1] > data[i]) // If left child is greater, return false
                return false;
            else if (data.size() > i * 2 + 2 && data[i * 2 + 1] > data[i]) // If right child EXISTS and is greater, return false
                return false;
        }
        return true;
    }

    bool Is_MaxHeap_1(const std::vector<int>& data)
    {
        const size_t size = data.size();
        for (size_t i = size; i >= 1; i--) {
            if (data[i / 2 - 1] < data[i - 1]) {
                return false;
            }
        }
        return true;
    }

    bool IsMaxHeap(const std::vector<int>& data)
    {
        for (size_t i = 0; i <= (data.size() / 2 - 1); i++) {
            if (data[i * 2 + 1] > data[i]) // If left child is greater, return false
                return false;
            else if (data.size() > i * 2 + 2 && data[i * 2 + 2] > data[i]) // If right child EXISTS and is greater, return false
                return false;
        }
        return true;
    }
}

void HeapsAlgorithms::Detect_Cycle()
{
    const std::vector<int>  data { 30,10,20,6,8,18,12,1,2,3,4,5,6,7,8,-13 };

    std::cout << std::boolalpha << Is_MaxHeap(data) << std::endl;
    std::cout << std::boolalpha << IsMaxHeap(data) << std::endl;
    std::cout << std::boolalpha << Is_MaxHeap_1(data) << std::endl;  // FIXME: Error
    std::cout << std::boolalpha << _is_max_heap_good(data) << std::endl;
    std::cout << std::boolalpha << std::is_heap(data.cbegin(), data.cend()) << std::endl;
}