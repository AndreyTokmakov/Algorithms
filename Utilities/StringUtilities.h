/**============================================================================
Name        : StringUtilities.h
Created on  : 08.02.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description : StringUtilities.h
============================================================================**/

#ifndef CPPPROJECTS_STRINGUTILITIES_H
#define CPPPROJECTS_STRINGUTILITIES_H

#include <vector>
#include <string>
#include <string_view>


namespace StringUtilities
{
    [[nodiscard]]
    std::vector<std::string> split(std::string_view input,
                                   std::string_view delimiter = " ");


    [[nodiscard]]
    std::vector<std::string> split(const std::string &str,
                                   const size_t partsExpected = 10,
                                   const std::string& delimiter = std::string {";"});

    void split_to(const std::string &str,
                  std::vector<std::string_view>& parts,
                  const std::string& delimiter = std::string {";"});


    void trim_1(std::string& str);
    void trim_2(std::string& str);
    void trim_3(std::string& str);

    std::string_view trim(const std::string& str);

    void strip(std::string &str);

    void remove_chars_from_string(std::string& str);

    [[nodiscard("Could be expensive to call. Do not discard the result")]]
    std::string randomString(size_t size = 16);
};


#endif //CPPPROJECTS_STRINGUTILITIES_H
