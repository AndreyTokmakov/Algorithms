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
		algorithms/Is_Palindrome.cpp
		algorithms/Remove_Chars_Of_One_String_FromAnother.cpp
		algorithms/Top_K_Frequent_Words.cpp
		algorithms/Remove_Duplicates_Chars.cpp
		algorithms/Reverse_String.cpp
		algorithms/Check_If_Strings_Rotate_Rotate_Equals.cpp
		algorithms/Move_Chars_To_End.cpp
		algorithms/Move_Zeros_To_End.cpp
		algorithms/Find_Last_Not_Of.cpp
		algorithms/Print_1_0_Instead_Wildcards.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_SOURCE_DIR}/Utilities")
target_link_directories(${PROJECT_NAME} PUBLIC "${CMAKE_BINARY_DIR}/Utilities")

TARGET_LINK_LIBRARIES(${PROJECT_NAME}
		utils
)