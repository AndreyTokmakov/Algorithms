/**============================================================================
Name        : Tests.cpp
Created on  : 15.09.2021
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description : Tests C++ project
============================================================================**/

#include <cstdlib>
#include <iostream>
#include <string_view>
#include <vector>

#include "StringUtilities.h"


int main([[maybe_unused]] const int argc,
         [[maybe_unused]] char** argv)
{
    const std::vector<std::string_view> args(argv + 1, argv + argc);

    std::cout << StringUtilities::randomString(128) << std::endl;


    return EXIT_SUCCESS;
}
