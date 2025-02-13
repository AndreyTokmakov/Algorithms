cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

project(Strings)
set(PROJECT_VERSION 1.0.0.0)
project(${PROJECT_NAME} VERSION ${PROJECT_VERSION} LANGUAGES CXX)

add_compile_options(-c -Wall -Wextra -O3 -std=c++23)

add_executable(${PROJECT_NAME}
    	main.cpp
		algorithms/Remove_Adjacent_Duplicates.cpp
		algorithms/Other.cpp
		algorithms/Find_If_String_IsSubstring_OfAnother.cpp
		algorithms/Find_Longest_Substring_With_K_Distinct_Characters.cpp
		algorithms/Find_First_K_Chars_Encountered_Once.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_SOURCE_DIR}/Utilities")
target_link_directories(${PROJECT_NAME} PUBLIC "${CMAKE_BINARY_DIR}/Utilities")

TARGET_LINK_LIBRARIES(${PROJECT_NAME}
		utils
)