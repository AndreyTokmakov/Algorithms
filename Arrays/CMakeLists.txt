cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

project(Arrays)
set(PROJECT_VERSION 1.0.0.0)
project(${PROJECT_NAME} VERSION ${PROJECT_VERSION} LANGUAGES CXX)

add_compile_options(-c -Wall -Wextra -O3 -std=c++26)

add_executable(${PROJECT_NAME}
    	main.cpp
		algorithms/other.cpp
		algorithms/Reverse_Bits.cpp
		algorithms/MidPoint.cpp
		algorithms/FixedPointSmallestIndexValueEqualIndex.cpp
		algorithms/Two_Sum_Less_Than_K.cpp
		algorithms/Add_Digits.cpp
		algorithms/Best_Time_Buy_and_Sell_Stock.cpp
		algorithms/Single_Number.cpp
		algorithms/Median_of_Two_Sorted_Arrays.cpp
		algorithms/Reverse_To_Make_Equal.cpp
		algorithms/Is_Reversed_Equals.cpp
		algorithms/Find_Top_K_Frequent_Numbers.cpp
		algorithms/Find_SubArrays_SumZero.cpp
		algorithms/Reverse_Number.cpp
		algorithms/Find_Element_Encountered_Only_Once.cpp
		algorithms/Is_Palindrome.cpp
		algorithms/Remove_Duplicates_From_Sorted_Array.cpp
		algorithms/Remove_Duplicates.cpp
		algorithms/Remove_Element.cpp
		algorithms/Contains_Duplicate.cpp
		algorithms/Find_Smallest_Missing_Positive_Number.cpp
		algorithms/Longest_Harmonious_Subsequence.cpp
		algorithms/Is_Prime.cpp
		algorithms/Coins_Change_Problem.cpp
		algorithms/Get_Number_Of_Digit.cpp
		algorithms/Greatest_Common_Divisor.cpp
		algorithms/Least_Common_Multiple.cpp
		algorithms/Is_Power_Of2.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_SOURCE_DIR}/Utilities")
target_link_directories(${PROJECT_NAME} PUBLIC "${CMAKE_BINARY_DIR}/Utilities")

TARGET_LINK_LIBRARIES(${PROJECT_NAME}
		utils
)