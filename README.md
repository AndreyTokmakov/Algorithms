# Algorithms
Demo Algorithms

1. [Overview](#Overview)
2. [Download](#Download)
3. [Requirements](#Requirements)
4. [Build](#Build)
5. [String Algorithms](#string_algorithms)
6. [Math and Arrays Algorithms](#math_arrays_algorithms)
7. [Linked List](#linked_list)
8. [Trees](#trees)
9. [Graphs](#graphs)
10. [Queues](#queues)
11. [Stack](#stack)
12. [Binary Search](#binary_search)
13. [Prefix Sums](#prefix_sums)
14. [Two Pointers](#two_pointers)

<a name="Overview"></a>
## Overview
Nothing special, just an attempt to structure and study C++ algorithms

<a name="Download"></a>
## Download project:
- Copy/clone the project repo: `git clone https://github.com/AndreyTokmakov/Algorithms.git`
- move to the project folder: `cd Algorithms`

<a name="Requirements"></a>
## Project requirements
- C++23 (.. but will compile even with C++17 ... just need to update CMakeList files)
- Cmake

<a name="Build"></a>
## Build
<a name="linux_build"></a>
### Linux
- Clone the project repo: `git clone https://github.com/AndreyTokmakov/Algorithms.git`
- Move to the project folder: `cd Algorithms`
- Configure project build (with cmake): `cmake -DCMAKE_BUILD_TYPE=Release -B./build`
- Build and compile solution: `cd build && make -j4`

<a id="string_algorithms"></a>
## String Algorithms
-  [Is_Palindrome](https://github.com/AndreyTokmakov/Algorithms/blob/bcb2d0be438634c1ccb0971cad4301397bded964/Strings/algorithms/Is_Palindrome.cpp#L20) <br/>
-  [Is_Palindrome_Ignore_Invalid_Chars](https://github.com/AndreyTokmakov/Algorithms/blob/main/Strings/algorithms/Is_Palindrome_Ignore_Invalid_Chars.cpp#L37)<br/>
-  [Is_String_Has_Only_Unique_Characters](https://github.com/AndreyTokmakov/Algorithms/blob/main/Strings/algorithms/Is_String_Has_Only_Unique_Characters.cpp#L18)<br/>
-  [Is_String_Contains_Another_String](https://github.com/AndreyTokmakov/Algorithms/blob/main/Strings/algorithms/Is_String_Contains_Another_String.cpp#L18)<br/>
-  [Are_Anagrams](https://github.com/AndreyTokmakov/Algorithms/blob/d6d4dfc40ded255cb55ef8c019008e5f1063785c/Strings/algorithms/Are_Anagrams.cpp#L22)<br/>
-  [Check_If_Strings_Rotate_Rotate_Equals](https://github.com/AndreyTokmakov/Algorithms/blob/d6d4dfc40ded255cb55ef8c019008e5f1063785c/Strings/algorithms/Check_If_Strings_Rotate_Rotate_Equals.cpp#L21)<br/>
-  [Check_If_Strings_Rotate_Rotate_Equals_2](https://github.com/AndreyTokmakov/Algorithms/blob/main/Strings/algorithms/Check_If_Strings_Rotate_Rotate_Equals_2.cpp#L35)<br/>
-  [Check_If_Two_Strings_Are_Permutation](https://github.com/AndreyTokmakov/Algorithms/blob/d6d4dfc40ded255cb55ef8c019008e5f1063785c/Strings/algorithms/Check_If_Two_Strings_Are_Permutation.cpp#L23 	)<br/>
-  [Find_First_Char_Encountered_Once](https://github.com/AndreyTokmakov/Algorithms/blob/d6d4dfc40ded255cb55ef8c019008e5f1063785c/Strings/algorithms/Find_First_Char_Encountered_Once.cpp#L20)<br/>
-  [Find_First_K_Chars_Encountered_Once](https://github.com/AndreyTokmakov/Algorithms/blob/d6d4dfc40ded255cb55ef8c019008e5f1063785c/Strings/algorithms/Find_First_K_Chars_Encountered_Once.cpp#L19)<br/>
-  [Find_If_String_IsSubstring_OfAnother](https://github.com/AndreyTokmakov/Algorithms/blob/d6d4dfc40ded255cb55ef8c019008e5f1063785c/Strings/algorithms/Find_If_String_IsSubstring_OfAnother.cpp#L22)<br/>
-  [Find_Last_Not_Of](https://github.com/AndreyTokmakov/Algorithms/blob/d6d4dfc40ded255cb55ef8c019008e5f1063785c/Strings/algorithms/Find_Last_Not_Of.cpp#L17)<br/>
-  [Find_Longest_Substring_With_K_Distinct_Characters](https://github.com/AndreyTokmakov/Algorithms/blob/d6d4dfc40ded255cb55ef8c019008e5f1063785c/Strings/algorithms/Find_Longest_Substring_With_K_Distinct_Characters.cpp#L22)<br/>
-  [Find_Common_Characters](https://github.com/AndreyTokmakov/Algorithms/blob/main/Strings/algorithms/Find_Common_Characters.cpp#L25)<br/>
-  [Move_Chars_To_End](https://github.com/AndreyTokmakov/Algorithms/blob/d6d4dfc40ded255cb55ef8c019008e5f1063785c/Strings/algorithms/Move_Chars_To_End.cpp#L21)<br/>
-  [Move_Zeros_To_End](https://github.com/AndreyTokmakov/Algorithms/blob/d6d4dfc40ded255cb55ef8c019008e5f1063785c/Strings/algorithms/Move_Zeros_To_End.cpp#L21)<br/>
-  [Print_1_0_Instead_Wildcards](https://github.com/AndreyTokmakov/Algorithms/blob/d6d4dfc40ded255cb55ef8c019008e5f1063785c/Strings/algorithms/Print_1_0_Instead_Wildcards.cpp#L23)<br/>
-  [Remove_Adjacent_Duplicates](https://github.com/AndreyTokmakov/Algorithms/blob/d6d4dfc40ded255cb55ef8c019008e5f1063785c/Strings/algorithms/Remove_Adjacent_Duplicates.cpp#L30)<br/>
-  [Remove_Chars_Of_One_String_FromAnother](https://github.com/AndreyTokmakov/Algorithms/blob/d6d4dfc40ded255cb55ef8c019008e5f1063785c/Strings/algorithms/Remove_Chars_Of_One_String_FromAnother.cpp#L20)<br/>
-  [Remove_Duplicates_Chars](https://github.com/AndreyTokmakov/Algorithms/blob/d6d4dfc40ded255cb55ef8c019008e5f1063785c/Strings/algorithms/Remove_Duplicates_Chars.cpp#L20)<br/>
-  [Reverse_String](https://github.com/AndreyTokmakov/Algorithms/blob/d6d4dfc40ded255cb55ef8c019008e5f1063785c/Strings/algorithms/Reverse_String.cpp#L21)<br/>
-  [Top_K_Frequent_Words](https://github.com/AndreyTokmakov/Algorithms/blob/d6d4dfc40ded255cb55ef8c019008e5f1063785c/Strings/algorithms/Top_K_Frequent_Words.cpp#L20)<br/>
-  [Check_Valid_Parentheses_3_Bracket](https://github.com/AndreyTokmakov/Algorithms/blob/d6d4dfc40ded255cb55ef8c019008e5f1063785c/Strings/algorithms/Check_Valid_Parentheses_3_Bracket.cpp#L19)<br/>
-  [Longest_Substring_Without_Repeating_Characters](https://github.com/AndreyTokmakov/Algorithms/blob/5f523bcea1a49736dc1e04b086ad564a1fb82109/Strings/algorithms/Longest_Substring_Without_Repeating_Characters.cpp#L20)<br/>
-  [Longest_Substring_Without_Repeating_Characters_2](https://github.com/AndreyTokmakov/Algorithms/blob/5f523bcea1a49736dc1e04b086ad564a1fb82109/Strings/algorithms/Longest_Substring_Without_Repeating_Characters_2.cpp#L20)<br/>
-  [To_Lower_Case](https://github.com/AndreyTokmakov/Algorithms/blob/2feec239c1f3f8ca954d0ee2704188ecd201b571/Strings/algorithms/To_Lower_Case.cpp#L18)<br/>
-  [Robot_Return_To_Origin](https://github.com/AndreyTokmakov/Algorithms/blob/2feec239c1f3f8ca954d0ee2704188ecd201b571/Strings/algorithms/Robot_Return_To_Origin.cpp#L37)<br/>
-  [String_To_Integer](https://github.com/AndreyTokmakov/Algorithms/blob/2feec239c1f3f8ca954d0ee2704188ecd201b571/Strings/algorithms/String_To_Integer.cpp#L18)<br/>
-  [String_To_Integer_2](https://github.com/AndreyTokmakov/Algorithms/blob/2feec239c1f3f8ca954d0ee2704188ecd201b571/Strings/algorithms/String_To_Integer_2.cpp#L27)<br/>
-  [Single_Row_Keyboard](https://github.com/AndreyTokmakov/Algorithms/blob/2feec239c1f3f8ca954d0ee2704188ecd201b571/Strings/algorithms/Single_Row_Keyboard.cpp#L44)<br/>
-  [Destination_City](https://github.com/AndreyTokmakov/Algorithms/blob/2feec239c1f3f8ca954d0ee2704188ecd201b571/Strings/algorithms/Destination_City.cpp#L52)<br/>
-  [Maximum_Consecutive_Characters_SubString](https://github.com/AndreyTokmakov/Algorithms/blob/608f9070c43f85c5ccb249ecb81985225af1a995/Strings/algorithms/Maximum_Consecutive_Characters_SubString.cpp#L28)<br/>
-  [Is_Words_Can_Be_Formed_by_Characters](https://github.com/AndreyTokmakov/Algorithms/blob/608f9070c43f85c5ccb249ecb81985225af1a995/Strings/algorithms/Is_Words_Can_Be_Formed_by_Characters.cpp#L26)<br/>
-  [Int_To_Roman](https://github.com/AndreyTokmakov/Algorithms/blob/408a1b3356bfa2c194db5eeb96befeba3d81690d/Strings/algorithms/Int_To_Roman.cpp#L34)<br/>
-  [Roman_To_Int](https://github.com/AndreyTokmakov/Algorithms/blob/408a1b3356bfa2c194db5eeb96befeba3d81690d/Strings/algorithms/Roman_To_Int.cpp#L20)<br/>
-  [Count_Anagrams](https://github.com/AndreyTokmakov/Algorithms/blob/408a1b3356bfa2c194db5eeb96befeba3d81690d/Strings/algorithms/Count_Anagrams.cpp#L29)<br/>
-  [Intersperse_String](https://github.com/AndreyTokmakov/Algorithms/blob/408a1b3356bfa2c194db5eeb96befeba3d81690d/Strings/algorithms/Intersperse_String.cpp#L18)<br/>
-  [Find_Longest_Word](https://github.com/AndreyTokmakov/Algorithms/blob/408a1b3356bfa2c194db5eeb96befeba3d81690d/Strings/algorithms/Find_Longest_Word.cpp#L18)<br/>
-  [Reverse_Words_in_String](https://github.com/AndreyTokmakov/Algorithms/blob/408a1b3356bfa2c194db5eeb96befeba3d81690d/Strings/algorithms/Reverse_Words_in_String.cpp#L30)<br/>
-  [Find_Common_Prefix_And_Postfix](https://github.com/AndreyTokmakov/Algorithms/blob/408a1b3356bfa2c194db5eeb96befeba3d81690d/Strings/algorithms/Find_Common_Prefix_And_Postfix.cpp#L26)<br/>
-  [Find_Duplicate_Symbols](https://github.com/AndreyTokmakov/Algorithms/blob/408a1b3356bfa2c194db5eeb96befeba3d81690d/Strings/algorithms/Find_Duplicate_Symbols.cpp#L18)<br/>
-  [Get_String_Length](https://github.com/AndreyTokmakov/Algorithms/blob/408a1b3356bfa2c194db5eeb96befeba3d81690d/Strings/algorithms/Get_String_Length.cpp#L18)<br/>
-  [Find_K_Most_Frequent_Character](https://github.com/AndreyTokmakov/Algorithms/blob/main/Strings/algorithms/Find_K_Most_Frequent_Character.cpp#L24)<br/>
-  [Longest_Substring_With_Maximum_K_Unique_Characters](https://github.com/AndreyTokmakov/Algorithms/blob/main/Strings/algorithms/Longest_Substring_With_Maximum_K_Unique_Characters.cpp#L21)<br/>
-  [Jewels_and_Stones](https://github.com/AndreyTokmakov/Algorithms/blob/main/Strings/algorithms/Jewels_and_Stones.cpp#L30)<br/>
-  [Simplify_Path](https://github.com/AndreyTokmakov/Algorithms/blob/main/Strings/algorithms/Simplify_Path.cpp#L26)<br/>
-  [Split_String_All_SubString_Don_Have_Same_Chars](https://github.com/AndreyTokmakov/Algorithms/blob/main/Strings/algorithms/Split_String_All_SubString_Don_Have_Same_Chars.cpp#L28)<br/>
-  [Longest_Palindrome](https://github.com/AndreyTokmakov/Algorithms/blob/main/Strings/algorithms/Longest_Palindrome.cpp#L18)<br/>
-  [Sort_String__Rearrange_String](https://github.com/AndreyTokmakov/Algorithms/blob/main/Strings/algorithms/Sort_String__Rearrange_String.cpp#L18)<br/>
-  [Sort_String__Rearrange_String_2](https://github.com/AndreyTokmakov/Algorithms/blob/main/Strings/algorithms/Sort_String__Rearrange_String_2.cpp#L17)<br/>
-  [Check_Valid_Parentheses_1_Bracket](https://github.com/AndreyTokmakov/Algorithms/blob/main/Strings/algorithms/Check_Valid_Parentheses_1_Bracket.cpp)<br/>
-  [Calc_Parentheses_K_Deletions_Make_Valid](https://github.com/AndreyTokmakov/Algorithms/blob/main/Strings/algorithms/Calc_Parentheses_K_Deletions_Make_Valid.cpp)<br/>
-  [Longest_Common_Prefix](https://github.com/AndreyTokmakov/Algorithms/blob/main/Strings/algorithms/Longest_Common_Prefix.cpp#L26)<br/>
-  [Compress_String](https://github.com/AndreyTokmakov/Algorithms/blob/main/Strings/algorithms/Compress_String.cpp#L31)<br/>
-  [Find_All_Anagrams_in_String](https://github.com/AndreyTokmakov/Algorithms/blob/main/Strings/algorithms/Find_All_Anagrams_in_String.cpp#L33)<br/>
-  [Letter_Case_Permutation](https://github.com/AndreyTokmakov/Algorithms/blob/main/Strings/algorithms/Letter_Case_Permutation.cpp#L29)<br/>
-  [Switch_Case](https://github.com/AndreyTokmakov/Algorithms/blob/main/Strings/algorithms/Switch_Case.cpp#L17)<br/>

<a id="math_arrays_algorithms"></a>
## Math and Arrays Algorithms
-  [Add_Digits](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Add_Digits.cpp#L23) <br/>
-  [Best_Time_Buy_and_Sell_Stock](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Best_Time_Buy_and_Sell_Stock.cpp#L30) <br/>
-  [Find_Element_Encountered_Only_Once](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Find_Element_Encountered_Only_Once.cpp#L26) <br/>
-  [Find_The_Duplicate_Value](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Find_The_Duplicate_Value.cpp#L41)<br/>
-  [Find_SubArrays_Sum_Zero](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Find_SubArrays_Sum_Zero.cpp#L30)<br/>
-  [Find_SubArrays_Sum_Equal_K](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Find_SubArrays_Sum_Equal_K.cpp#L19)<br/>
-  [Find_SubArray_Sum_Equal_K_Single](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Find_SubArray_Sum_Equal_K_Single.cpp#L22)<br/>
-  [Find_Top_K_Frequent_Numbers](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Find_Top_K_Frequent_Numbers.cpp#L16) <br/>
-  [Find_N_Min_Elements](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Find_N_Min_Elements.cpp#L17) <br/>
-  [Find_N_Max_Elements](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Find_N_Max_Elements.cpp#L17) <br/>
-  [Find_Rank](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Find_Rank.cpp#L38) <br/>
-  [Find_First_Repeating_Element](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Find_First_Repeating_Element.cpp#L32) <br/>
-  [Find_Multiplier_Pair](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Find_Multiplier_Pair.cpp#L19) <br/>
-  [Find_Peak_Element](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Find_Peak_Element.cpp#L40) <br/>
-  [Find_Missing_Number](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Find_Missing_Number.cpp) <br/>
-  [Find_Missing_Number_2](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Find_Missing_Number_2.cpp) <br/>
-  [Find_Missing_Number_Any_Range](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Find_Missing_Number_Any_Range.cpp) <br/>
-  [Find_Missing_Number_Sorted_Array](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Find_Missing_Number_Sorted_Array.cpp#L18)<br/>
-  [Find_Missing_K_Number_Sorted_Array](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Find_Missing_K_Number_Sorted_Array.cpp#L18)<br/>
-  [Find_Missing_K_Positive_Number_Sorted_Array](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Find_Missing_K_Positive_Number_Sorted_Array.cpp#L27)<br/>
-  [Find_Missing_K_Number_Unsorted](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Find_Missing_K_Number_Unsorted.cpp#L18)<br/>
-  [Find_Longest_SubArray_K_Unique_Elements](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Find_Longest_SubArray_K_Unique_Elements.cpp#L20)<br/>
-  [Find_Longest_Increasing_Subsequence](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Find_Longest_Increasing_Subsequence.cpp#L18)<br/>
-  [Find_Smallest_Without_Compare](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Find_Smallest_Without_Compare.cpp#L20)<br/>
-  [Find_Index_In_Array_to_make_Right_Equal_Left](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Find_Index_In_Array_to_make_Right_Equal_Left.cpp#L19)<br/>
-  [Find_Smallest_Missing_Positive_Number](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Find_Smallest_Missing_Positive_Number.cpp#L17)<br/>
-  [Find_The_Majority_Element](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Find_The_Majority_Element.cpp#L27)<br/>
-  [Median_of_Two_Sorted_Arrays](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Median_of_Two_Sorted_Arrays.cpp#L26)<br/>
-  [MidPoint](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/MidPoint.cpp#L16) <br/>
-  [Reverse_Bits](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Reverse_Bits.cpp#L26) <br/>
-  [Reverse_Number](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Reverse_Number.cpp#L25) <br/>
-  [Reverse_To_Make_Equal](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Reverse_To_Make_Equal.cpp#L16) <br/>
-  [Single_Number](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Single_Number.cpp#L29) <br/>
-  [Two_Sum_Less_Than_K](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Two_Sum_Less_Than_K.cpp#L23) <br/>
-  [Remove_Duplicates_From_Sorted_Array](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Remove_Duplicates_From_Sorted_Array.cpp#L28)<br/>
-  [Remove_Duplicates](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Remove_Duplicates.cpp#L18)<br/>
-  [Remove_Element](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Remove_Element.cpp#L19)<br/>
-  [Contains_Duplicate](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Contains_Duplicate.cpp#L18)<br/>
-  [Longest_Harmonious_Subsequence](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Longest_Harmonious_Subsequence.cpp#L25)<br/>
-  [Is_Palindrome](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Is_Palindrome.cpp#L17)<br/>
-  [Is_Reversed_Equals](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Is_Reversed_Equals.cpp#L15)<br/>
-  [Is_Prime](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Is_Prime.cpp#L18)<br/>
-  [Is_Power_Of2](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Is_Power_Of2.cpp#L18)<br/>
-  [Is_Permutation](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Is_Permutation.cpp#L18) <br/>
-  [Coins_Change_Problem](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Coins_Change_Problem.cpp#L19)<br/>
-  [Get_Number_Of_Digit](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Get_Number_Of_Digit.cpp#L18)<br/>
-  [Greatest_Common_Divisor](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Greatest_Common_Divisor.cpp#L27)<br/>
-  [Least_Common_Multiple](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Least_Common_Multiple.cpp#L18)<br/>
-  [Can_Jump](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Can_Jump.cpp#L25)<br/>
-  [Maximum_Sum_SubArray_Algorithms_Kadane](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Maximum_Sum_SubArray_Algorithms_Kadane.cpp#L18)<br/>
-  [Sort_Array_By_Parity](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Sort_Array_By_Parity.cpp#L24)<br/>
-  [Contains_Nearby_Duplicates](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Contains_Nearby_Duplicates.cpp#L27)<br/>
-  [Divide_Without_Division_Operator](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Divide_Without_Division_Operator.cpp#L18)<br/>
-  [Longest_Consecutive_Sequence](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Longest_Consecutive_Sequence.cpp#L18)<br/>
-  [Add_One_to_Integer_Array](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Add_One_to_Integer_Array.cpp#L27)<br/>
-  [Sqrt](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Sqrt.cpp#L17)<br/>
-  [Min_Length_SubArray_WithSameDegree](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Min_Length_SubArray_WithSameDegree.cpp#L42)<br/>
-  [Maximum_Area_Between_Boundaries](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Maximum_Area_Between_Boundaries.cpp#L30)<br/>
-  [Calculate_Max_Hotel_Visitors](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Calculate_Max_Hotel_Visitors.cpp#L23)<br/>
-  [Smallest_Subarray_With_Sum_Greater_Than_K](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Smallest_Subarray_With_Sum_Greater_Than_K.cpp#L18)<br/>
-  [Sum_of_Sub_Array_Between_Indexes_L_and_R](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Sum_of_Sub_Array_Between_Indexes_L_and_R.cpp#L19)<br/>
-  [Fixed_Point_SmallestIndex_ValueEqualIndex](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/FixedPointSmallestIndexValueEqualIndex.cpp#L25)<br/>
-  [Longest_Subarray_With_Sum_Less_Than_K](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Longest_Subarray_With_Sum_Less_Than_K.cpp#L18)<br/>
-  [Squares_of_a_Sorted_Array](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Squares_of_a_Sorted_Array.cpp#L33)<br/>
-  [Container_With_Most_Water](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Container_With_Most_Water.cpp#L25)<br/>
-  [Unique_Permutations](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Unique_Permutations.cpp#L22)<br/>
-  [House_Robber](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/House_Robber.cpp#L38)<br/>
-  [Single_Number_2](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Single_Number_2.cpp#L28)<br/>
-  [Find_First_and_Last_Position_of_Element_Sorter_Arrays](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Find_First_and_Last_Position_of_Element_Sorter_Arrays.cpp#L34)<br/>
-  [Longest_Subset_With_Positive_Bitwise_AND](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Longest_Subset_With_Positive_Bitwise_AND.cpp#L32)<br/>
-  [Find_Pair_Sum_Equal_K](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Find_Pair_Sum_Equal_K.cpp#L31)<br/>
-  [Kadane_Algorithm](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Kadane_Algorithm.cpp#L18)<br/>
-  [First_Bad_Version](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/First_Bad_Version.cpp#L46)<br/>
-  [Sort_Colors](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Sort_Colors.cpp#L27)<br/>
-  [Find_Pair_Sum_Equal_K_Sorted_Array](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Find_Pair_Sum_Equal_K_Sorted_Array.cpp#L32)<br/>
-  [Count_Distinct_Pairs_With_Difference_K](Count_Distinct_Pairs_With_Difference_K)<br/>
-  [Delete_Each_Second_Value_in_Array](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Delete_Each_Second_Value_in_Array.cpp#L17)<br/>
-  [Product_of_Array_Except_Self](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Product_of_Array_Except_Self.cpp#L28)<br/>
-  [Find_Pair_with_Maximum_Sum](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Find_Pair_with_Maximum_Sum.cpp#L17)<br/>
-  [Find_First_Element_Occured_Odd_Times](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Find_First_Element_Occured_Odd_Times.cpp#L18)<br/>
-  [Maximum_Product_SubArray](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Maximum_Product_SubArray.cpp#L29)<br/>
-  [Online_Stock_Spanner_DailyPrices](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Online_Stock_Spanner_DailyPrices.cpp#L50)<br/>
-  [Find_Repeating_And_Missing](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Find_Repeated_and_Missing_Numbers.cpp#L18)<br/>
-  [Longest_Fibonacci_SubArray](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Longest_Fibonacci_SubArray.cpp#L17)<br/>
-  [Is_Array_Consecutive](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Is_Array_Consecutive.cpp#L17)<br/>

<a id="linked_list"></a>
## Linked List
-  [Add_Two_Numbers](https://github.com/AndreyTokmakov/Algorithms/blob/main/LinkedList/algorithms/Add_Two_Numbers.cpp#L27)<br/>
-  [Check_If_Palindrome](https://github.com/AndreyTokmakov/Algorithms/blob/main/LinkedList/algorithms/Check_If_Palindrome.cpp#L20)<br/>
-  [Check_List_Is_Cycled](https://github.com/AndreyTokmakov/Algorithms/blob/main/LinkedList/algorithms/Check_List_Is_Cycled.cpp#L20)<br/>
-  [Delete_Duplicates](https://github.com/AndreyTokmakov/Algorithms/blob/main/LinkedList/algorithms/Delete_Duplicates.cpp#L20)<br/>
-  [Delete_Duplicates_SortedList](https://github.com/AndreyTokmakov/Algorithms/blob/main/LinkedList/algorithms/Delete_Duplicates_SortedList.cpp#L18)<br/>
-  [Delete_K_Element_From_the_End](https://github.com/AndreyTokmakov/Algorithms/blob/main/LinkedList/algorithms/Delete_K_Element_From_the_End.cpp#L18)<br/>
-  [Delete_Node_By_Position](https://github.com/AndreyTokmakov/Algorithms/blob/main/LinkedList/algorithms/Delete_Node_By_Position.cpp#L19C25-L19C26)<br/>
-  [Delete_Nodes_By_Value](https://github.com/AndreyTokmakov/Algorithms/blob/main/LinkedList/algorithms/Delete_Nodes_By_Value.cpp#L18)<br/>
-  [Find_Middle_Element](https://github.com/AndreyTokmakov/Algorithms/blob/main/LinkedList/algorithms/Find_Middle_Element.cpp#L17)<br/>
-  [Find_Nth_Element_FromTheEnd](https://github.com/AndreyTokmakov/Algorithms/blob/main/LinkedList/algorithms/Find_Nth_Element_FromTheEnd.cpp#L20)<br/>
-  [Get_Length](https://github.com/AndreyTokmakov/Algorithms/blob/main/LinkedList/algorithms/Get_Length.cpp#L18)<br/>
-  [Insert_Into_Sorted_List](https://github.com/AndreyTokmakov/Algorithms/blob/main/LinkedList/algorithms/Insert_Into_Sorted_List.cpp#L18)<br/>
-  [Merge_Two_Lists](https://github.com/AndreyTokmakov/Algorithms/blob/main/LinkedList/algorithms/Merge_Two_Lists.cpp#L19)<br/>
-  [Move_All_Occurrences_To_The_End](https://github.com/AndreyTokmakov/Algorithms/blob/main/LinkedList/algorithms/Move_All_Occurrences_To_The_End.cpp#L19)<br/>
-  [Remove_N_Node_From_End](https://github.com/AndreyTokmakov/Algorithms/blob/main/LinkedList/algorithms/Remove_N_Node_From_End.cpp#L18)<br/>
-  [Reverse_List](https://github.com/AndreyTokmakov/Algorithms/blob/main/LinkedList/algorithms/Reverse_List.cpp#L18)<br/>
-  [Merge_K_Sorter_Lists](https://github.com/AndreyTokmakov/Algorithms/blob/main/LinkedList/algorithms/Merge_K_Sorter_Lists.cpp#L28)<br/>

<a id="trees"></a>
## Trees
-  [Find_Lowest_Common_Ancestor](https://github.com/AndreyTokmakov/Algorithms/blob/main/Trees/algorithms/Find_Lowest_Common_Ancestor.cpp#L17)<br/>
-  [Find_Min_and_Max_Element_NonRecursive](https://github.com/AndreyTokmakov/Algorithms/blob/main/Trees/algorithms/Find_Min_and_Max_Element_NonRecursive.cpp#L18)<br/>
-  [Find_Min_and_Max_Element_Recursive](https://github.com/AndreyTokmakov/Algorithms/blob/main/Trees/algorithms/Find_Min_and_Max_Element_Recursive.cpp#L18)<br/>
-  [Find_N_th_MinElement](https://github.com/AndreyTokmakov/Algorithms/blob/main/Trees/algorithms/Find_N_th_MinElement.cpp#L17)<br/>
-  [Find_N_th_Smallest_Element](https://github.com/AndreyTokmakov/Algorithms/blob/main/Trees/algorithms/Find_N_th_Smallest_Element.cpp#L18)<br/>
-  [Largest_Element_In_Each_Level](https://github.com/AndreyTokmakov/Algorithms/blob/main/Trees/algorithms/Largest_Element_In_Each_Level.cpp#L18)<br/>
-  [Sorted_Array_To_Binary_Tree](https://github.com/AndreyTokmakov/Algorithms/blob/main/Trees/algorithms/Sorted_Array_To_Binary_Tree.cpp#L18)<br/>
-  [Sorted_Array_To_Binary_Tree_NonRecursive](https://github.com/AndreyTokmakov/Algorithms/blob/main/Trees/algorithms/Sorted_Array_To_Binary_Tree_NonRecursive.cpp#L17)<br/>
-  [Find_Lowest_Common_Ancestor](https://github.com/AndreyTokmakov/Algorithms/blob/main/Trees/algorithms/Find_Lowest_Common_Ancestor.cpp#L17)<br/>
-  [Count_Elements](https://github.com/AndreyTokmakov/Algorithms/blob/main/Trees/algorithms/Count_Elements.cpp#L22)<br/>
-  [Get_Tree_Depth](https://github.com/AndreyTokmakov/Algorithms/blob/main/Trees/algorithms/Get_Tree_Depth.cpp#L23)<br/>
-  [Check_Is_Tree_Symmetric](https://github.com/AndreyTokmakov/Algorithms/blob/main/Trees/algorithms/Check_Is_Tree_Symmetric.cpp#L57)<br/>
-  [Check_Is_Trees_Identical](https://github.com/AndreyTokmakov/Algorithms/blob/main/Trees/algorithms/Check_Is_Trees_Identical.cpp#L23)<br/>
-  [Check_Is_Tree_Balanced](https://github.com/AndreyTokmakov/Algorithms/blob/main/Trees/algorithms/Check_Is_Tree_Balanced.cpp#L49)<br/>
-  [Find_Maximum_Level_Sum](https://github.com/AndreyTokmakov/Algorithms/blob/main/Trees/algorithms/Find_Maximum_Level_Sum.cpp#L21)<br/>
-  [Find_Path_Sum_Between_Two_Nodes](Find_Path_Sum_Between_Two_Nodes)<br/>
-  [Find_Maximum_Node_At_Given_Level](Find_Maximum_Node_At_Given_Level)<br/>
-  [Find_Level_With_Maximum_Sum](https://github.com/AndreyTokmakov/Algorithms/blob/main/Trees/algorithms/Find_Level_With_Maximum_Sum.cpp#L18)<br/>
-  [Find_Search_Element_in_BST](https://github.com/AndreyTokmakov/Algorithms/blob/main/Trees/algorithms/Find_Search_Element_in_BST.cpp#L18)<br/>
-  [Find_Deepest_Node](https://github.com/AndreyTokmakov/Algorithms/blob/main/Trees/algorithms/Find_Deepest_Node.cpp#L18)<br/>
-  [Find_Element_Parent](https://github.com/AndreyTokmakov/Algorithms/blob/main/Trees/algorithms/Find_Element_Parent.cpp#L18)<br/>
-  [Find_If_Last_Level_Completed](https://github.com/AndreyTokmakov/Algorithms/blob/main/Trees/algorithms/Find_If_Last_Level_Completed.cpp#L17)<br/>
-  [Check_Is_Binary_Search_Tree_BST](https://github.com/AndreyTokmakov/Algorithms/blob/main/Trees/algorithms/Check_Is_Binary_Search_Tree_BST.cpp#L18)<br/>
-  [Check_Is_Tree_Complete](https://github.com/AndreyTokmakov/Algorithms/blob/main/Trees/algorithms/Check_Is_Tree_Complete.cpp#L19)<br/>
-  [Get_Tree_Min_Depth](https://github.com/AndreyTokmakov/Algorithms/blob/main/Trees/algorithms/Get_Tree_Min_Depth.cpp#L38)<br/>
-  [Print_Left_View](https://github.com/AndreyTokmakov/Algorithms/blob/main/Trees/algorithms/Print_Left_View.cpp#L18)<br/>
-  [Print_Right_View](https://github.com/AndreyTokmakov/Algorithms/blob/main/Trees/algorithms/Print_Right_View.cpp#L18)<br/>
-  [Print_Top_View](https://github.com/AndreyTokmakov/Algorithms/blob/main/Trees/algorithms/Print_Top_View.cpp#L18)<br/>
-  [Tree_Traversal_Level_Order](https://github.com/AndreyTokmakov/Algorithms/blob/main/Trees/algorithms/Tree_Traversal_Level_Order.cpp#L30)<br/>
-  [Tree_Traversal_Inorder](https://github.com/AndreyTokmakov/Algorithms/blob/main/Trees/algorithms/Tree_Traversal_Inorder.cpp#L31)<br/>
-  [Tree_Traversal_Backward](https://github.com/AndreyTokmakov/Algorithms/blob/main/Trees/algorithms/Tree_Traversal_Backward.cpp#L28)<br/>
-  [Tree_Traversal_PreOrder](https://github.com/AndreyTokmakov/Algorithms/blob/main/Trees/algorithms/Tree_Traversal_PreOrder.cpp#L43)<br/>
-  [Tree_Traversal_PostOrder](https://github.com/AndreyTokmakov/Algorithms/blob/main/Trees/algorithms/Tree_Traversal_PostOrder.cpp#L42)<br/>

<a id="graphs"></a>
## Graphs
-  [Breadth First Search](https://github.com/AndreyTokmakov/Algorithms/blob/main/Graphs/algorithms/BFS.cpp#L55)<br/>
-  [Depth First Search](https://github.com/AndreyTokmakov/Algorithms/blob/main/Graphs/algorithms/DFS.cpp#L105)<br/>
-  [DFS_NonRecur](https://github.com/AndreyTokmakov/Algorithms/blob/main/Graphs/algorithms/DFS_NonRecur.cpp#L83)<br/>
-  [Find_Shortest_Path](https://github.com/AndreyTokmakov/Algorithms/blob/main/Graphs/algorithms/Find_Shortest_Path.cpp#L63)<br/>
-  [Detect_Cycle](https://github.com/AndreyTokmakov/Algorithms/blob/main/Graphs/algorithms/Detect_Cycle.cpp#L52)<br/>

<a id="queues"></a>
## Queues
-  [Queue_Using_Stacks](https://github.com/AndreyTokmakov/Algorithms/blob/main/Queues/algorithms/Queue_Using_Stacks.cpp#L19)<br/>
-  [Queue_Using_Stacks_Recursive](https://github.com/AndreyTokmakov/Algorithms/blob/main/Queues/algorithms/Queue_Using_Stacks_Recursive.cpp#L18)<br/>

<a id="stack"></a>
## Stack:
-  [MinStack](https://github.com/AndreyTokmakov/Algorithms/blob/main/Stack/algorithms/MinStack.cpp#L20)<br/>
-  [Stack_Using_One_Queue](https://github.com/AndreyTokmakov/Algorithms/blob/main/Stack/algorithms/Stack_Using_One_Queue.cpp#L20)<br/>
-  [Stack_Using_Two_Queues](https://github.com/AndreyTokmakov/Algorithms/blob/main/Stack/algorithms/Stack_Using_Two_Queues.cpp#L19)<br/>

<a id="binary_search"></a>
## BinarySearch:
-  [Sqrt](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Sqrt.cpp#L17)<br/>
-  [Find_Smallest_Letter_Greater_Than_Target](https://github.com/AndreyTokmakov/Algorithms/blob/main/BinarySearch/algorithms/Find_Smallest_Letter_Greater_Than_Target.cpp#L31)<br/>
-  [Binary_Search](https://github.com/AndreyTokmakov/Algorithms/blob/main/BinarySearch/algorithms/Binary_Search.cpp#L35)<br/>

<a id="prefix_sums"></a>
## Prefix Sums:
-  [Find_Longest_SubArray_K_Unique_Elements](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Find_Longest_SubArray_K_Unique_Elements.cpp#L20)<br/>
-  [Find_Index_In_Array_to_make_Right_Equal_Left](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Find_Index_In_Array_to_make_Right_Equal_Left.cpp#L19)<br/>
-  [Sum_of_Sub_Array_Between_Indexes_L_and_R](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Sum_of_Sub_Array_Between_Indexes_L_and_R.cpp#L19)<br/>
-  [Longest_Subarray_With_Sum_Less_Than_K](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Longest_Subarray_With_Sum_Less_Than_K.cpp#L18)<br/>

<a id="two_pointers"></a>
## Two Pointers:
-  [Squares_of_a_Sorted_Array](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Squares_of_a_Sorted_Array.cpp#L33)<br/>
-  [Container_With_Most_Water](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Container_With_Most_Water.cpp#L25)<br/>
-  [Is_Palindrome_Ignore_Invalid_Chars](https://github.com/AndreyTokmakov/Algorithms/blob/main/Strings/algorithms/Is_Palindrome_Ignore_Invalid_Chars.cpp#L37)<br/>
-  [Sort_Colors](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Sort_Colors.cpp#L27)<br/>
-  [Find_Pair_Sum_Equal_K_Sorted_Array](https://github.com/AndreyTokmakov/Algorithms/blob/main/Arrays/algorithms/Find_Pair_Sum_Equal_K_Sorted_Array.cpp#L32)<br/>