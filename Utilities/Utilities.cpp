/**============================================================================
Name        : Utilities.cpp
Created on  : 08.02.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description : Utilities.cpp
============================================================================**/

#include "Utilities.h"
#include <iostream>


namespace Utilities
{
    ScopedTimer::~ScopedTimer()
    {
        const std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
        const std::chrono::duration<double> time_span = duration_cast<std::chrono::duration<double>>(end - start);

        std::cout << std::left << std::setw(14) << benchmarkName << ":  ";
        std::cout << time_span.count() << " seconds.\n";
    }
}
