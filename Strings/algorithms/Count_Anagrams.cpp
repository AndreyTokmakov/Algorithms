/**============================================================================
Name        : Count_Anagrams.cpp
Created on  : 20.01.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../StringAlgorithms.h"
#include "StringUtilities.h"


/**
 * Have the function CountingAnagrams(str) take the str parameter and determine how many anagrams exist in the string.
 * An anagram is a new word that is produced from rearranging the characters in a different word,
 * Program should determine how many anagrams exist in a given string and return the total number.
 * For example: if str is "aa aa odg dog gdo" then your program should return 2 because "dog" and "gdo" are
 * anagrams of "odg".
 * The word "aa" occurs twice in the string but it isn't an anagram because it is the same word just repeated.
 * The string will contain only spaces and lowercase letters, no punctuation, numbers, or uppercase letters.
*/

namespace
{
    using namespace StringAlgorithms;

    int are_anagrams(const std::string_view& str1,
                     const std::string_view& str2)
    {
        if (str1 == str2 || str1.length() != str2.length())
            return 0;

        int chars[256] = { 0 };
        for (const char c : str1)
            chars[c]++;
        for (const char c : str2)
            if (1 > chars[c]--)
                return 0;
        return 1;
    }

    int count_anagrams(const std::string& input)
    {
        std::vector<std::string_view> words;
        StringUtilities::split_to(input, words, " ");

        int count = 0;
        for (int i = 0; i < words.size(); ++i ){
            for (int n = 0; n < words.size(); ++n)
                count += are_anagrams(words[i], words[n]);
        }

        return count / 2;
    }
}

void StringAlgorithms::Count_Anagrams()
{
    for (const auto  &[value, expected]: std::vector<std::pair<std::string, int>> {
              {"cars are very cool so are arcs and my os", 2},
              {"a c b c run urn", 1},
              {"aa aa ab ba dog god", 2},
              {"ab ba run run run", 1},
              // {"abcd abdc bcda adbc abbc", 3},

      })
    {
        const int actual = count_anagrams(value);
        if (expected != actual) {
            std::cerr << expected << " != " << actual << std::endl;
            return;
        }
    }
    std::cout << "OK: All tests passed\n";
}
