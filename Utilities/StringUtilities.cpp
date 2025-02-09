/**============================================================================
Name        : StringUtilities.cpp
Created on  : 08.02.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description : StringUtilities.cpp
============================================================================**/

#include "StringUtilities.h"

#include <array>
#include <algorithm>
#include <random>

namespace StringUtilities
{
    std::string randomString(size_t size)
    {
        std::random_device rd{};
        std::mt19937 generator = std::mt19937 {rd()};
        auto ud = std::uniform_int_distribution<> {(int)'a', (int)'z'};

        std::string str;
        str.reserve(size);
        while (size-- > 0)
            str.push_back(static_cast<char>(ud(generator)));
        return str;
    }

    std::vector<std::string> split(std::string_view input,
                                   std::string_view delimiter)
    {
        std::vector<std::string> output;
        for (size_t first = 0; first < input.size();) {
            const auto second = input.find_first_of(delimiter, first);
            if (first != second)
                output.emplace_back(input.substr(first, second - first));
            if (second == std::string_view::npos)
                break;
            first = second + 1;
        }
        return output;
    }

    // TODO: Check for performance: delimiter : std::string ---> std::string_view
    [[nodiscard]]
    std::vector<std::string> split(const std::string &str,
                                   const size_t partsExpected,
                                   const std::string &delimiter)
    {
        std::vector<std::string> parts{};
        parts.reserve(partsExpected);
        size_t pos = 0, prev = 0;
        while ((pos = str.find(delimiter, prev)) != std::string::npos) {
            parts.emplace_back(str, prev, pos - prev);
            prev = pos + delimiter.length();
        }
        parts.emplace_back(str, prev, str.length() - prev);
        return parts;
    }

    // TODO: Check for performance: delimiter : std::string ---> std::string_view
    void split_to(const std::string &str,
                  std::vector<std::string_view> &parts,
                  const std::string &delimiter)
    {
        parts.clear();
        size_t pos = 0, prev = 0;
        while ((pos = str.find(delimiter, prev)) != std::string::npos) {
            parts.emplace_back(str.data() + prev, pos - prev);
            prev = pos + delimiter.length();
        }
        parts.emplace_back(str.data() + prev, str.length() - prev);
    }
}

namespace StringUtilities
{
    // Remove ' ', '\t', '\n', '\r', '\n' symbols from the END and BEGINING of the string
    void strip(std::string &str)
    {
        constexpr std::array<char, 5> symbols{' ', '\t', '\n', '\r', '\n'};

        std::string::size_type start = 0, length = str.length();
        while (length > start && std::any_of(symbols.cbegin(), symbols.cend(), [&](const char c) {
            return c == str[start];
        })) { ++start; }
        str.erase(0, start);;

        std::string::size_type end = length - start - 1;
        while (end && std::any_of(symbols.cbegin(), symbols.cend(), [&](const char c) {
            return c == str[end];
        })) { --end; }
        str.erase(end + 1, length - start - end);

        str.shrink_to_fit();
    }
}

namespace StringUtilities
{
    constexpr std::array<char, 256> toExclude = []() -> std::array<char, 256> {
        std::array<char, 256> tmp{};
        for (const char c: {'\t', '\n', '\r', '\n'})
            tmp[c] = 1;
        return tmp;
    }();

    void remove_chars_from_string(std::string &str)
    {
        size_t index = 0;
        for (char c: str) {
            if (0 == toExclude[c])
                str[index++] = c;
        }
        str.resize(index);
        str.shrink_to_fit();
    }
}


namespace StringUtilities
{
    void trim_1(std::string& str)
    {
        size_t beg = 0, end = str.length();
        for (; end > beg & str[beg] == ' '; beg++) {}
        for (; end > 0 && str[--end] == ' '; ) {}
        str = str.substr(beg, end - beg + 1);
    }

    void trim_2(std::string& str)
    {
        str.erase(0, str.find_first_not_of(' '));
        std::reverse(str.begin(), str.end());
        str.erase(0, str.find_first_not_of(' '));
        std::reverse(str.begin(), str.end());
    }

    void trim_3(std::string &str)
    {
        std::string::size_type start = 0, length = str.length();
        while (length > start && str[start] == ' ') { ++start; }
        str.erase(0, start);

        std::string::size_type end = length - start - 1;
        while (end && str[end] == ' ') { --end; }
        str.erase(end + 1, length - start - end);

        str.shrink_to_fit();
    }

    std::string_view trim(const std::string &str)
    {
        std::string::size_type start = 0, end = str.length() - 1;
        while (str.length() > start && str[start] == ' ') { ++start; }
        while (end && str[end] == ' ') { --end; }
        return std::string_view{str.data() + start, end - start + 1};
    }
}