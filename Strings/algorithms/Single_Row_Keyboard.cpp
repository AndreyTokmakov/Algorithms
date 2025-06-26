/**============================================================================
Name        : Single_Row_Keyboard.cpp
Created on  : 18.01.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../StringAlgorithms.h"

/**
There is a special keyboard with all keys in a single row.
Given a string keyboard of length 26 indicating the layout of the keyboard
(indexed from 0 to 25), initially your finger is at index 0. To type a
character, you have to move your finger to the index of the desired character.
The time taken to move your finger from index i to index j is |i - j|.
You want to type a string word. Write a function to calculate how much time it
takes to type it with one finger.
Example 1:
Input: keyboard = "abcdefghijklmnopqrstuvwxyz", word = "cba"

Output: 4
Explanation: The index moves from 0 to 2 to write 'c' then to 1 to write 'b'
then to 0 again to write 'a'.
Total time = 2 + 1 + 1 = 4.

Example 2:
Input: keyboard = "pqrstuvwxyzabcdefghijklmno", word = "leetcode"
Output: 73

Constraints:
keyboard.length == 26
keyboard contains each English lowercase letter exactly once in some order.
1 <= word.length <= 10^4
word[i] is an English lowercase letter.
**/

namespace
{
    using namespace StringAlgorithms;

    int calculateTime(const std::string& keyboard,
                      const std::string& word)
    {
        uint8_t map[32] {};
        for (int pos = 0; const char c: keyboard) {
            map[c - 'a'] = pos++;
        }

        int ret = 0;
        for (int prevPos = 0; const char c: word) {
            ret += abs(map[c - 'a'] - prevPos);
            prevPos = map[c - 'a'];
        }
        return ret;
    }
}

void StringAlgorithms::Single_Row_Keyboard()
{
    using TestData = std::vector<std::pair<std::pair<std::string, std::string>, int>>;
    for (const auto& [value, expected]:  TestData{
        { {"abcdefghijklmnopqrstuvwxyz", "cba"} , 4 },
        { {"pqrstuvwxyzabcdefghijklmno", "leetcode"} , 73 },
    })
    {
        const auto& [keyboard, word] = value;
        const int actual = calculateTime(keyboard, word);
        if (expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
    }
    std::cout << "OK: All tests passed\n";
}
