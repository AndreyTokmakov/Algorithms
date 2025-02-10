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
)

target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_SOURCE_DIR}/Utilities")
target_link_directories(${PROJECT_NAME} PUBLIC "${CMAKE_BINARY_DIR}/Utilities")

TARGET_LINK_LIBRARIES(${PROJECT_NAME}
		utils
)