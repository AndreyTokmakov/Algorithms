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
		algorithms/Single_Number_2.cpp
		algorithms/Median_of_Two_Sorted_Arrays.cpp
		algorithms/Reverse_To_Make_Equal.cpp
		algorithms/Is_Reversed_Equals.cpp
		algorithms/Find_Top_K_Frequent_Numbers.cpp
        algorithms/Find_SubArrays_Sum_Zero.cpp
		algorithms/Find_SubArrays_Sum_Equal_K.cpp
		algorithms/Find_N_Min_Elements.cpp
		algorithms/Find_N_Max_Elements.cpp
		algorithms/Find_The_Duplicate_Value.cpp
		algorithms/Reverse_Number.cpp
		algorithms/Find_Element_Encountered_Only_Once.cpp
		algorithms/Find_First_and_Last_Position_of_Element_Sorter_Arrays.cpp
		algorithms/Is_Palindrome.cpp
		algorithms/Is_Permutation.cpp
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
		algorithms/Find_The_Majority_Element.cpp
		algorithms/Can_Jump.cpp
		algorithms/Divide_Without_Division_Operator.cpp
		algorithms/Maximum_Sum_SubArray_Algorithms_Kadane.cpp
		algorithms/Sort_Array_By_Parity.cpp
		algorithms/Contains_Nearby_Duplicates.cpp
		algorithms/Longest_Consecutive_Sequence.cpp
		algorithms/Add_One_to_Integer_Array.cpp
		algorithms/Sqrt.cpp
		algorithms/Min_Length_SubArray_WithSameDegree.cpp
		algorithms/Maximum_Area_Between_Boundaries.cpp
		algorithms/Calculate_Max_Hotel_Visitors.cpp
		algorithms/Find_SubArrays_Sum_Equal_K.cpp
		algorithms/Find_SubArray_Sum_Equal_K_Single.cpp
		algorithms/Smallest_Subarray_With_Sum_Greater_Than_K.cpp
		algorithms/Find_Longest_SubArray_K_Unique_Elements.cpp
		algorithms/Sum_of_Sub_Array_Between_Indexes_L_and_R.cpp
		algorithms/Find_Index_In_Array_to_make_Right_Equal_Left.cpp
		algorithms/Find_Smallest_Without_Compare.cpp
		algorithms/Squares_of_a_Sorted_Array.cpp
		algorithms/Longest_Subarray_With_Sum_Less_Than_K.cpp
		algorithms/Container_With_Most_Water.cpp
		algorithms/Find_Longest_Increasing_Subsequence.cpp
		algorithms/Find_Rank.cpp
		algorithms/Find_First_Repeating_Element.cpp
		algorithms/Find_Multiplier_Pair.cpp
		algorithms/Find_Peak_Element.cpp
		algorithms/Is_Permutation.cpp
		algorithms/Find_Missing_Number.cpp
		algorithms/Find_Missing_Number_2.cpp
		algorithms/Find_Missing_Number_Any_Range.cpp
		algorithms/Find_Missing_Number_Sorted_Array.cpp
		algorithms/Unique_Permutations.cpp
		algorithms/Find_Missing_K_Number_Sorted_Array.cpp
		algorithms/Find_Missing_K_Positive_Number_Sorted_Array.cpp
		algorithms/Find_Missing_K_Number_Unsorted.cpp
		algorithms/House_Robber.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_SOURCE_DIR}/Utilities")
target_link_directories(${PROJECT_NAME} PUBLIC "${CMAKE_BINARY_DIR}/Utilities")

TARGET_LINK_LIBRARIES(${PROJECT_NAME}
		utils
)