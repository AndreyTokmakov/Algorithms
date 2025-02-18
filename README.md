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
-  [Are_Anagrams](https://github.com/AndreyTokmakov/Algorithms/blob/d6d4dfc40ded255cb55ef8c019008e5f1063785c/Strings/algorithms/Are_Anagrams.cpp#L22)<br/>
-  [Check_If_Strings_Rotate_Rotate_Equals](https://github.com/AndreyTokmakov/Algorithms/blob/d6d4dfc40ded255cb55ef8c019008e5f1063785c/Strings/algorithms/Check_If_Strings_Rotate_Rotate_Equals.cpp#L21)<br/>
-  [Check_If_Two_Strings_Are_Permutation](https://github.com/AndreyTokmakov/Algorithms/blob/d6d4dfc40ded255cb55ef8c019008e5f1063785c/Strings/algorithms/Check_If_Two_Strings_Are_Permutation.cpp#L23 	)<br/>
-  [Find_First_Char_Encountered_Once](https://github.com/AndreyTokmakov/Algorithms/blob/d6d4dfc40ded255cb55ef8c019008e5f1063785c/Strings/algorithms/Find_First_Char_Encountered_Once.cpp#L20)<br/>
-  [Find_First_K_Chars_Encountered_Once](https://github.com/AndreyTokmakov/Algorithms/blob/d6d4dfc40ded255cb55ef8c019008e5f1063785c/Strings/algorithms/Find_First_K_Chars_Encountered_Once.cpp#L19)<br/>
-  [Find_If_String_IsSubstring_OfAnother](https://github.com/AndreyTokmakov/Algorithms/blob/d6d4dfc40ded255cb55ef8c019008e5f1063785c/Strings/algorithms/Find_If_String_IsSubstring_OfAnother.cpp#L22)<br/>
-  [Find_Last_Not_Of](https://github.com/AndreyTokmakov/Algorithms/blob/d6d4dfc40ded255cb55ef8c019008e5f1063785c/Strings/algorithms/Find_Last_Not_Of.cpp#L17)<br/>
-  [Find_Longest_Substring_With_K_Distinct_Characters](https://github.com/AndreyTokmakov/Algorithms/blob/d6d4dfc40ded255cb55ef8c019008e5f1063785c/Strings/algorithms/Find_Longest_Substring_With_K_Distinct_Characters.cpp#L22)<br/>
-  [Move_Chars_To_End](https://github.com/AndreyTokmakov/Algorithms/blob/d6d4dfc40ded255cb55ef8c019008e5f1063785c/Strings/algorithms/Move_Chars_To_End.cpp#L21)<br/>
-  [Move_Zeros_To_End](https://github.com/AndreyTokmakov/Algorithms/blob/d6d4dfc40ded255cb55ef8c019008e5f1063785c/Strings/algorithms/Move_Zeros_To_End.cpp#L21)<br/>
-  [Print_1_0_Instead_Wildcards](https://github.com/AndreyTokmakov/Algorithms/blob/d6d4dfc40ded255cb55ef8c019008e5f1063785c/Strings/algorithms/Print_1_0_Instead_Wildcards.cpp#L23)<br/>
-  [Remove_Adjacent_Duplicates](https://github.com/AndreyTokmakov/Algorithms/blob/d6d4dfc40ded255cb55ef8c019008e5f1063785c/Strings/algorithms/Remove_Adjacent_Duplicates.cpp#L30)<br/>
-  [Remove_Chars_Of_One_String_FromAnother](https://github.com/AndreyTokmakov/Algorithms/blob/d6d4dfc40ded255cb55ef8c019008e5f1063785c/Strings/algorithms/Remove_Chars_Of_One_String_FromAnother.cpp#L20)<br/>
-  [Remove_Duplicates_Chars](https://github.com/AndreyTokmakov/Algorithms/blob/d6d4dfc40ded255cb55ef8c019008e5f1063785c/Strings/algorithms/Remove_Duplicates_Chars.cpp#L20)<br/>
-  [Reverse_String](https://github.com/AndreyTokmakov/Algorithms/blob/d6d4dfc40ded255cb55ef8c019008e5f1063785c/Strings/algorithms/Reverse_String.cpp#L21)<br/>
-  [Top_K_Frequent_Words](https://github.com/AndreyTokmakov/Algorithms/blob/d6d4dfc40ded255cb55ef8c019008e5f1063785c/Strings/algorithms/Top_K_Frequent_Words.cpp#L20)<br/>
-  [Calc_Parentheses_3_Bracket](https://github.com/AndreyTokmakov/Algorithms/blob/d6d4dfc40ded255cb55ef8c019008e5f1063785c/Strings/algorithms/Calc_Parentheses_3_Bracket.cpp#L19)<br/>
-  [Longest_Substring_Without_Repeating_Characters](https://github.com/AndreyTokmakov/Algorithms/blob/5f523bcea1a49736dc1e04b086ad564a1fb82109/Strings/algorithms/Longest_Substring_Without_Repeating_Characters.cpp#L20)<br/>
-  [Longest_Substring_Without_Repeating_Characters_2](https://github.com/AndreyTokmakov/Algorithms/blob/5f523bcea1a49736dc1e04b086ad564a1fb82109/Strings/algorithms/Longest_Substring_Without_Repeating_Characters_2.cpp#L20)<br/>

<a id="math_arrays_algorithms"></a>
## Math and Arrays Algorithms
-  [Add_Digits](https://github.com/AndreyTokmakov/Algorithms/blob/5f523bcea1a49736dc1e04b086ad564a1fb82109/Arrays/algorithms/Add_Digits.cpp#L23) <br/>
-  [Best_Time_Buy_and_Sell_Stock](https://github.com/AndreyTokmakov/Algorithms/blob/5f523bcea1a49736dc1e04b086ad564a1fb82109/Arrays/algorithms/Best_Time_Buy_and_Sell_Stock.cpp#L30) <br/>
-  [Find_Element_Encountered_Only_Once](https://github.com/AndreyTokmakov/Algorithms/blob/5f523bcea1a49736dc1e04b086ad564a1fb82109/Arrays/algorithms/Find_Element_Encountered_Only_Once.cpp#L26) <br/>
-  [Find_SubArrays_SumZero](https://github.com/AndreyTokmakov/Algorithms/blob/5f523bcea1a49736dc1e04b086ad564a1fb82109/Arrays/algorithms/Find_SubArrays_SumZero.cpp#L15) <br/>
-  [Find_Top_K_Frequent_Numbers](https://github.com/AndreyTokmakov/Algorithms/blob/5f523bcea1a49736dc1e04b086ad564a1fb82109/Arrays/algorithms/Find_Top_K_Frequent_Numbers.cpp#L16) <br/>
-  [Is_Reversed_Equals](https://github.com/AndreyTokmakov/Algorithms/blob/5f523bcea1a49736dc1e04b086ad564a1fb82109/Arrays/algorithms/Is_Reversed_Equals.cpp#L15) <br/>
-  [Median_of_Two_Sorted_Arrays](https://github.com/AndreyTokmakov/Algorithms/blob/5f523bcea1a49736dc1e04b086ad564a1fb82109/Arrays/algorithms/Median_of_Two_Sorted_Arrays.cpp#L26) <br/>
-  [MidPoint](https://github.com/AndreyTokmakov/Algorithms/blob/5f523bcea1a49736dc1e04b086ad564a1fb82109/Arrays/algorithms/MidPoint.cpp#L16) <br/>
-  [Reverse_Bits](https://github.com/AndreyTokmakov/Algorithms/blob/5f523bcea1a49736dc1e04b086ad564a1fb82109/Arrays/algorithms/Reverse_Bits.cpp#L26) <br/>
-  [Reverse_Number](https://github.com/AndreyTokmakov/Algorithms/blob/5f523bcea1a49736dc1e04b086ad564a1fb82109/Arrays/algorithms/Reverse_Number.cpp#L25) <br/>
-  [Reverse_To_Make_Equal](https://github.com/AndreyTokmakov/Algorithms/blob/5f523bcea1a49736dc1e04b086ad564a1fb82109/Arrays/algorithms/Reverse_To_Make_Equal.cpp#L16) <br/>
-  [Single_Number](https://github.com/AndreyTokmakov/Algorithms/blob/5f523bcea1a49736dc1e04b086ad564a1fb82109/Arrays/algorithms/Single_Number.cpp#L29) <br/>
-  [Two_Sum_Less_Than_K](https://github.com/AndreyTokmakov/Algorithms/blob/5f523bcea1a49736dc1e04b086ad564a1fb82109/Arrays/algorithms/Two_Sum_Less_Than_K.cpp#L23) <br/>
-  [Remove_Duplicates_From_Sorted_Array](https://github.com/AndreyTokmakov/Algorithms/blob/6df0032f61d3cca0c0c9ed8eb4aa1a6ca2747eb8/Arrays/algorithms/Remove_Duplicates_From_Sorted_Array.cpp#L28)<br/>
-  [Remove_Duplicates](https://github.com/AndreyTokmakov/Algorithms/blob/6df0032f61d3cca0c0c9ed8eb4aa1a6ca2747eb8/Arrays/algorithms/Remove_Duplicates.cpp#L18)<br/>
-  [Remove_Element](https://github.com/AndreyTokmakov/Algorithms/blob/6df0032f61d3cca0c0c9ed8eb4aa1a6ca2747eb8/Arrays/algorithms/Remove_Element.cpp#L19)<br/>
-  [Contains_Duplicate](https://github.com/AndreyTokmakov/Algorithms/blob/6df0032f61d3cca0c0c9ed8eb4aa1a6ca2747eb8/Arrays/algorithms/Contains_Duplicate.cpp#L18)<br/>
-  [Find_Smallest_Missing_Positive_Number](https://github.com/AndreyTokmakov/Algorithms/blob/6df0032f61d3cca0c0c9ed8eb4aa1a6ca2747eb8/Arrays/algorithms/Find_Smallest_Missing_Positive_Number.cpp#L17)<br/>
-  [Longest_Harmonious_Subsequence](https://github.com/AndreyTokmakov/Algorithms/blob/8f8f2ff22cf57719ab5af2c65ccdcb2ab090979e/Arrays/algorithms/Longest_Harmonious_Subsequence.cpp#L25)<br/>
-  [Is_Prime](https://github.com/AndreyTokmakov/Algorithms/blob/8f8f2ff22cf57719ab5af2c65ccdcb2ab090979e/Arrays/algorithms/Is_Prime.cpp#L18)<br/>
-  [Coins_Change_Problem](https://github.com/AndreyTokmakov/Algorithms/blob/8f8f2ff22cf57719ab5af2c65ccdcb2ab090979e/Arrays/algorithms/Coins_Change_Problem.cpp#L19)<br/>
-  [Get_Number_Of_Digit](https://github.com/AndreyTokmakov/Algorithms/blob/8f8f2ff22cf57719ab5af2c65ccdcb2ab090979e/Arrays/algorithms/Get_Number_Of_Digit.cpp#L18)<br/>
-  [Greatest_Common_Divisor](https://github.com/AndreyTokmakov/Algorithms/blob/8f8f2ff22cf57719ab5af2c65ccdcb2ab090979e/Arrays/algorithms/Greatest_Common_Divisor.cpp#L27)<br/>
-  [Least_Common_Multiple](https://github.com/AndreyTokmakov/Algorithms/blob/8f8f2ff22cf57719ab5af2c65ccdcb2ab090979e/Arrays/algorithms/Least_Common_Multiple.cpp#L18)<br/>
-  [Is_Power_Of2](https://github.com/AndreyTokmakov/Algorithms/blob/8f8f2ff22cf57719ab5af2c65ccdcb2ab090979e/Arrays/algorithms/Is_Power_Of2.cpp#L18)<br/>
-  [Find_The_Majority_Element](https://github.com/AndreyTokmakov/Algorithms/blob/69603dd9203873533bd66491f1936d57da357bd3/Arrays/algorithms/Find_The_Majority_Element.cpp#L27)<br/>
-  [Can_Jump](https://github.com/AndreyTokmakov/Algorithms/blob/69603dd9203873533bd66491f1936d57da357bd3/Arrays/algorithms/Can_Jump.cpp#L25)<br/>
-  [Maximum_Sum_SubArray_Algorithms_Kadane](https://github.com/AndreyTokmakov/Algorithms/blob/69603dd9203873533bd66491f1936d57da357bd3/Arrays/algorithms/Maximum_Sum_SubArray_Algorithms_Kadane.cpp#L18)<br/>
-  [Sort_Array_By_Parity](https://github.com/AndreyTokmakov/Algorithms/blob/69603dd9203873533bd66491f1936d57da357bd3/Arrays/algorithms/Sort_Array_By_Parity.cpp#L24)<br/>
-  [Contains_Nearby_Duplicates](https://github.com/AndreyTokmakov/Algorithms/blob/9e71d8a6e1a3d994c913d668ba4462c45358e71b/Arrays/algorithms/Contains_Nearby_Duplicates.cpp#L27)<br/>
-  [Divide_Without_Division_Operator](https://github.com/AndreyTokmakov/Algorithms/blob/d8c4cc25914e549bf86bbe43241d2831b00e8286/Arrays/algorithms/Divide_Without_Division_Operator.cpp#L18)<br/>

<a id="linked_list"></a>
## Linked List
-  [Add_Two_Numbers](https://github.com/AndreyTokmakov/Algorithms/blob/102d26b9776287516bc34c0e73da4d3fa11f3e21/LinkedList/algorithms/Add_Two_Numbers.cpp#L27)<br/>
-  [Check_If_Palindrome](https://github.com/AndreyTokmakov/Algorithms/blob/102d26b9776287516bc34c0e73da4d3fa11f3e21/LinkedList/algorithms/Check_If_Palindrome.cpp#L20)<br/>
-  [Check_List_Is_Cycled](https://github.com/AndreyTokmakov/Algorithms/blob/102d26b9776287516bc34c0e73da4d3fa11f3e21/LinkedList/algorithms/Check_List_Is_Cycled.cpp#L20)<br/>
-  [Delete_Duplicates](https://github.com/AndreyTokmakov/Algorithms/blob/102d26b9776287516bc34c0e73da4d3fa11f3e21/LinkedList/algorithms/Delete_Duplicates.cpp#L20)<br/>
-  [Delete_Duplicates_SortedList](https://github.com/AndreyTokmakov/Algorithms/blob/102d26b9776287516bc34c0e73da4d3fa11f3e21/LinkedList/algorithms/Delete_Duplicates_SortedList.cpp#L18)<br/>
-  [Delete_K_Element_From_the_End](https://github.com/AndreyTokmakov/Algorithms/blob/102d26b9776287516bc34c0e73da4d3fa11f3e21/LinkedList/algorithms/Delete_K_Element_From_the_End.cpp#L18)<br/>
-  [Delete_Node_By_Position](https://github.com/AndreyTokmakov/Algorithms/blob/102d26b9776287516bc34c0e73da4d3fa11f3e21/LinkedList/algorithms/Delete_Node_By_Position.cpp#L19C25-L19C26)<br/>
-  [Delete_Nodes_By_Value](https://github.com/AndreyTokmakov/Algorithms/blob/102d26b9776287516bc34c0e73da4d3fa11f3e21/LinkedList/algorithms/Delete_Nodes_By_Value.cpp#L18)<br/>
-  [Find_Middle_Element](https://github.com/AndreyTokmakov/Algorithms/blob/102d26b9776287516bc34c0e73da4d3fa11f3e21/LinkedList/algorithms/Find_Middle_Element.cpp#L17)<br/>
-  [Find_Nth_Element_FromTheEnd](https://github.com/AndreyTokmakov/Algorithms/blob/102d26b9776287516bc34c0e73da4d3fa11f3e21/LinkedList/algorithms/Find_Nth_Element_FromTheEnd.cpp#L20)<br/>
-  [Get_Length](https://github.com/AndreyTokmakov/Algorithms/blob/102d26b9776287516bc34c0e73da4d3fa11f3e21/LinkedList/algorithms/Get_Length.cpp#L18)<br/>
-  [Insert_Into_Sorted_List](https://github.com/AndreyTokmakov/Algorithms/blob/102d26b9776287516bc34c0e73da4d3fa11f3e21/LinkedList/algorithms/Insert_Into_Sorted_List.cpp#L18)<br/>
-  [Merge_Two_Lists](https://github.com/AndreyTokmakov/Algorithms/blob/102d26b9776287516bc34c0e73da4d3fa11f3e21/LinkedList/algorithms/Merge_Two_Lists.cpp#L19)<br/>
-  [Move_All_Occurrences_To_The_End](https://github.com/AndreyTokmakov/Algorithms/blob/102d26b9776287516bc34c0e73da4d3fa11f3e21/LinkedList/algorithms/Move_All_Occurrences_To_The_End.cpp#L19)<br/>
-  [Remove_N_Node_From_End](https://github.com/AndreyTokmakov/Algorithms/blob/102d26b9776287516bc34c0e73da4d3fa11f3e21/LinkedList/algorithms/Remove_N_Node_From_End.cpp#L18)<br/>
-  [Reverse_List](https://github.com/AndreyTokmakov/Algorithms/blob/102d26b9776287516bc34c0e73da4d3fa11f3e21/LinkedList/algorithms/Reverse_List.cpp#L18)<br/>

<a id="trees"></a>
## Trees
-  [Find_Lowest_Common_Ancestor](https://github.com/AndreyTokmakov/Algorithms/blob/6df0032f61d3cca0c0c9ed8eb4aa1a6ca2747eb8/Trees/algorithms/Find_Lowest_Common_Ancestor.cpp#L17)<br/>
-  [Find_Min_and_Max_Element_NonRecursive](https://github.com/AndreyTokmakov/Algorithms/blob/6df0032f61d3cca0c0c9ed8eb4aa1a6ca2747eb8/Trees/algorithms/Find_Min_and_Max_Element_NonRecursive.cpp#L18)<br/>
-  [Find_Min_and_Max_Element_Recursive](https://github.com/AndreyTokmakov/Algorithms/blob/6df0032f61d3cca0c0c9ed8eb4aa1a6ca2747eb8/Trees/algorithms/Find_Min_and_Max_Element_Recursive.cpp#L18)<br/>
-  [Find_N_th_MinElement](https://github.com/AndreyTokmakov/Algorithms/blob/6df0032f61d3cca0c0c9ed8eb4aa1a6ca2747eb8/Trees/algorithms/Find_N_th_MinElement.cpp#L17)<br/>
-  [Find_N_th_Smallest_Element](https://github.com/AndreyTokmakov/Algorithms/blob/6df0032f61d3cca0c0c9ed8eb4aa1a6ca2747eb8/Trees/algorithms/Find_N_th_Smallest_Element.cpp#L18)<br/>
-  [Largest_Element_In_Each_Level](https://github.com/AndreyTokmakov/Algorithms/blob/6df0032f61d3cca0c0c9ed8eb4aa1a6ca2747eb8/Trees/algorithms/Largest_Element_In_Each_Level.cpp#L18)<br/>
-  [Sorted_Array_To_Binary_Tree](https://github.com/AndreyTokmakov/Algorithms/blob/6df0032f61d3cca0c0c9ed8eb4aa1a6ca2747eb8/Trees/algorithms/Sorted_Array_To_Binary_Tree.cpp#L18)<br/>
-  [Sorted_Array_To_Binary_Tree_NonRecursive](https://github.com/AndreyTokmakov/Algorithms/blob/6df0032f61d3cca0c0c9ed8eb4aa1a6ca2747eb8/Trees/algorithms/Sorted_Array_To_Binary_Tree_NonRecursive.cpp#L17)<br/>
-  [Find_Lowest_Common_Ancestor](https://github.com/AndreyTokmakov/Algorithms/blob/8f8f2ff22cf57719ab5af2c65ccdcb2ab090979e/Trees/algorithms/Find_Lowest_Common_Ancestor.cpp#L17)<br/>
-  [Count_Elements](https://github.com/AndreyTokmakov/Algorithms/blob/8f8f2ff22cf57719ab5af2c65ccdcb2ab090979e/Trees/algorithms/Count_Elements.cpp#L22)<br/>
-  [Get_Tree_Depth](https://github.com/AndreyTokmakov/Algorithms/blob/8f8f2ff22cf57719ab5af2c65ccdcb2ab090979e/Trees/algorithms/Get_Tree_Depth.cpp#L23)<br/>