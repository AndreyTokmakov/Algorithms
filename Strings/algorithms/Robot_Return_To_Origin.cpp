/**============================================================================
Name        : Robot_Return_To_Origin.cpp
Created on  : 18.01.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../StringAlgorithms.h"

/**
There is a robot starting at position (0, 0), the origin, on a 2D plane.
Given a sequence of its moves, judge if this robot ends up at (0, 0) after it completes its moves.
The move sequence is represented by a string, and the character moves[i] represents its ith move.
Valid moves are R (right), L (left), U (up), and D (down).
If the robot returns to the origin after it finishes all of its moves, return true.
Otherwise, return false.
Note: The way that the robot is "facing" is irrelevant. "R" will always make the
robot move to the right once, "L" will always make it move left, etc. Also,
assume that the magnitude of the robot's movement is the same for each move.

Example 1:   Input: "UD" Output: true
Explanation: The robot moves up once, and then down once. All moves have the same magnitude,
             so it ended up at the origin where it started. Therefore, we return true.

Example 2:   Input: "LL", Output: false
Explanation: The robot moves left twice. It ends up two "moves" to the left of the origin.
             We return false because it is not at the origin at the end of its moves.
**/

namespace
{
    using namespace StringAlgorithms;

    bool judgeCircle(const std::string& moves)
    {
        int h = 0, v = 0;
        for (const char ch : moves) {
            switch (ch) {
                case 'L': --h; break;
                case 'R': ++h; break;
                case 'D': --v; break;
                case 'U': ++v; break;
                default:       break;
            }
        }
        return h == 0 && v == 0;
    }
}

void StringAlgorithms::Robot_Return_To_Origin()
{
    using TestData = std::vector<std::pair<std::string, bool> >;
    for (const auto& [moves, expected]:  TestData {
            { "UD" , true },
            { "LL" , false },
    })
    {
        bool result = judgeCircle(moves);
        if (expected != result) {
            std::cerr << moves << " | " <<  std::boolalpha << expected << " != " << result << std::endl;
        }
    }
    std::cout << "OK: All tests passed\n";
}
