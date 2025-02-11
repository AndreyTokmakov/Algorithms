cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

project(Utilities)
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -pthread")
set(PROJECT_VERSION 1.0.0.0)
project(${PROJECT_NAME} VERSION ${PROJECT_VERSION} LANGUAGES CXX)

add_compile_options(-c -Wall -Wextra -O3 -std=c++23)

add_library(utils
        Utilities.cpp Utilities.h
        StringUtilities.cpp StringUtilities.h
)

# include all components
add_executable(${PROJECT_NAME}
        main.cpp
        ../Arrays/ArraysAlgorithms.h
)

target_link_libraries(${PROJECT_NAME}
        utils
        pthread
        ${EXTRA_LIBS}
)