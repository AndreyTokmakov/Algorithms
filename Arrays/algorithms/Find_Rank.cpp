/**============================================================================
Name        : Find_Rank.cpp
Created on  : 26.02.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../ArraysAlgorithms.h"

#include <ranges>

/**
Scientists are publishing papers, and these papers are getting cited in other papers.
Find the rank of the scientist.
Rank: largest R, such that at least R papers have >= R citations

std::vector<uint32_t> papers {3, 4, 5, 11}; ->  3
std::vector<uint32_t> papers {2, 4, 11};   ->  2
**/

namespace
{
    using namespace ArraysAlgorithms;

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
}

void ArraysAlgorithms::Find_Rank()
{
    using TestData = std::vector< std::pair<std::vector<uint32_t>, uint32_t> >;
    for (const auto& [papers, expected]:  TestData{
        { { 3, 4, 5, 11 } , 3 },
        { { 2, 4, 11 } , 2 },
    })
    {
        if (const auto actual = find_rank(papers); expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
    }
    std::cout << "OK: All tests passed\n";
}