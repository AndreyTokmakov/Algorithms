/**============================================================================
Name        : Maximal_Square.cpp
Created on  : 12.03.2025
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

    int maximal_square(const std::vector<std::vector<int>>& matrix)
    {
        if (matrix.empty() || matrix.front().empty())
            return 0;

        int maxSquare = 0;
        const int rows = static_cast<int>(matrix.size()), cols = static_cast<int>(matrix.front().size());
        std::vector<std::vector<int>> dp(rows + 1, std::vector<int>(cols + 1, 0));
        for (int idxRow = 0; idxRow < rows; idxRow++)
        {
            for (int idxCol = 0; idxCol < cols; idxCol++)
            {
                dp[idxRow + 1][idxCol + 1] = matrix[idxRow][idxCol];
                if (dp[idxRow + 1][idxCol + 1] > 0)
                {
                    dp[idxRow + 1][idxCol + 1] = std::min(dp[idxRow][idxCol],
                        std::min(dp[idxRow][idxCol + 1], dp[idxRow + 1][idxCol])) + 1;
                    maxSquare = std::max(maxSquare, dp[idxRow + 1][idxCol + 1]);
                }
            }
        }
        return maxSquare;
    }

    int maximalSquare(const std::vector<std::vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
        int mx = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] ==1) {
                    dp[i + 1][j + 1] = std::min(std::min(dp[i][j + 1], dp[i + 1][j]), dp[i][j]) + 1;
                    mx = std::max(mx, dp[i + 1][j + 1]);
                }
            }
        }
        return mx * mx;
    }


    int maximal_square_2(const std::vector<std::vector<int>>& matrix)
    {
        if (matrix.empty() || matrix.front().empty())
            return 0;

        bool flag = false;
        int maxSquare = 0;
        const int rows = static_cast<int>(matrix.size()), cols = static_cast<int>(matrix.front().size());

        int stvCol = 0, stRow = 0;
        for (int idxRow = 0 ; idxRow < rows; idxRow++)
        {

            for (int idxCol = 0; idxCol < cols; idxCol++)
            {
                if (1 == matrix[idxRow][idxCol])
                {
                    if (flag )
                    {
                        if (idxRow >= stRow && idxCol >= stvCol)
                        {
                            std::cout << idxRow << ' ' << idxCol << " OK 1 ST: {" << stRow << ", " << stvCol << "} ==> ";
                            std::cout << (idxCol + 1- stvCol) * (idxRow + 1- stRow) << '\n';
                            maxSquare = std::max(maxSquare, (idxCol + 1- stvCol) * (idxRow + 1- stRow));
                        }
                    }
                    else
                    {
                        if (idxRow >= stRow && idxCol >= stvCol)
                        {
                            std::cout << idxRow << ' ' << idxCol << " OK 2 ST: {" << stRow << ", " << stvCol << "} ==> ";
                            std::cout << (idxCol + 1- stvCol) * (idxRow + 1- stRow) << '\n';
                        }

                        stRow = idxRow;
                        stvCol = idxCol;
                        std::cout << "Updated {" << stRow << ", " << stvCol << "}\n";
                    }
                    flag = true;
                }
                else
                {
                    flag = false;
                }
            }
            //std::cout << std::endl;
        }
        return maxSquare;
    }

}


void ArraysAlgorithms::Maximal_Square()
{   // 1 0 1 0 0        1 0 0 0 0
    // 1 0 1 1 1        1 1 0 0 0
    // 1 1 1 1 1        1 1 0 0 0
    // 1 0 0 1 0        1 1 0 0 0

    using TestData = std::vector< std::pair<std::vector<std::vector<int>>, int>>;
    for (const auto& [values, expected]:  TestData {
        { {{1,0,1,0,0}, {1,0,1,1,1}, {1,1,1,1,1}, {1,0,0,1,0}} , 6 },
        { {{1,0,0,0,0}, {1,1,0,0,0}, {1,1,0,0,0}, {1,1,0,0,0}} , 6 },
    })
    {
        const auto actual = maximalSquare(values);
        std::cout << actual << '\n';

        /*if (expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }*/
    }
    std::cout << "OK: All tests passed\n";
}
