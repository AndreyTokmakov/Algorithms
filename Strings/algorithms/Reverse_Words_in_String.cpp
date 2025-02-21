/**============================================================================
Name        : Reverse_Words_in_String.cpp
Created on  : 20.01.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../StringAlgorithms.h"

/**
 * Given an input string s, reverse the order of the words.
 * A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.
 * Return a string of the words in reverse order concatenated by a single space.
 * Note that s may contain leading or trailing spaces or multiple spaces between two words.
 * The returned string should only have a single space separating the words. Do not include any extra spaces.
 *
 * "the sky is blue"   --> "blue is sky the"
 * "  hello world  "   --> "world hello"
 * "a good   example"  -->  "example good a"
 *
*/

namespace
{
    using namespace StringAlgorithms;

    std::string reverse_words_in_string(const std::string& str)
    {
        std::string result;
        result.reserve(str.size());

        size_t pos = 0, prev = 0;
        while ((pos = str.find(' ', prev)) != std::string::npos) {
            if (pos > prev)
                result.insert(0, str, prev, pos - prev).insert(0, " ");
            prev = pos + 1;
        }
        result.insert(0, str, prev, str.length() - prev);
        if (result.front() == ' ')
            result.erase(0,1);
        result.shrink_to_fit();
        return result;
    }
}

void StringAlgorithms::Reverse_Words_in_String()
{
    for (const std::string& str: std::vector<std::string> {
            {"the sky is blue" }, {"a  good   example   " }, {" asdasd df f"}, {"  hello world  "}
    })
    {
        std::cout << '\'' << str << "' --> '" << reverse_words_in_string(str) << "\'\n";
    }
}