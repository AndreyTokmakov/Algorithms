cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

project(Trees)
set(PROJECT_VERSION 1.0.0.0)
project(${PROJECT_NAME} VERSION ${PROJECT_VERSION} LANGUAGES CXX)

add_compile_options(-c -Wall -Wextra -O3 -std=c++23)

add_executable(${PROJECT_NAME}
    	main.cpp
		algorithms/Other.cpp
		algorithms/Find_N_th_MinElement.cpp
		algorithms/Largest_Element_In_Each_Level.cpp
		algorithms/Find_Min_and_Max_Element_Recursive.cpp
		algorithms/Find_Min_and_Max_Element_NonRecursive.cpp
		algorithms/Find_N_th_Smallest_Element.cpp
		algorithms/Find_Level_With_Maximum_Sum.cpp
		algorithms/Sorted_Array_To_Binary_Tree.cpp
		algorithms/Sorted_Array_To_Binary_Tree_NonRecursive.cpp
		algorithms/Find_Lowest_Common_Ancestor.cpp
		algorithms/Count_Elements.cpp
		algorithms/Find_Maximum_Node_At_Given_Level.cpp
		algorithms/Get_Tree_Depth.cpp
		algorithms/Get_Tree_Min_Depth.cpp
		algorithms/Check_Is_Trees_Identical.cpp
		algorithms/Check_Is_Tree_Symmetric.cpp
		algorithms/Check_Is_Tree_Balanced.cpp
		algorithms/Check_Is_Binary_Search_Tree_BST.cpp
		algorithms/Tree_Traversal_Level_Order.cpp
		algorithms/Tree_Traversal_Inorder.cpp
		algorithms/Tree_Traversal_Backward.cpp
		algorithms/Tree_Traversal_PreOrder.cpp
		algorithms/Tree_Traversal_PostOrder.cpp
		algorithms/Find_Maximum_Level_Sum.cpp
		algorithms/Find_Path_Sum_Between_Two_Nodes.cpp
		algorithms/Print_Tree_Pretty.cpp
		algorithms/Find_Search_Element_in_BST.cpp
		algorithms/Find_Deepest_Node.cpp
		algorithms/Find_Element_Parent.cpp
		algorithms/Find_If_Last_Level_Completed.cpp
		algorithms/Check_Is_Tree_Complete.cpp
		algorithms/Print_Top_View.cpp
		algorithms/Print_Right_View.cpp
		algorithms/Print_Left_View.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_SOURCE_DIR}/Utilities")
target_link_directories(${PROJECT_NAME} PUBLIC "${CMAKE_BINARY_DIR}/Utilities")

TARGET_LINK_LIBRARIES(${PROJECT_NAME}
		utils
)