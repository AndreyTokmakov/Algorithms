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
		algorithms/Sorted_Array_To_Binary_Tree.cpp
		algorithms/Sorted_Array_To_Binary_Tree_NonRecursive.cpp
		algorithms/Find_Lowest_Common_Ancestor.cpp
		algorithms/Count_Elements.cpp
		algorithms/Get_Tree_Depth.cpp
		algorithms/Check_Is_Trees_Identical.cpp
		algorithms/Check_Is_Tree_Symmetric.cpp
		algorithms/Check_Is_Tree_Balanced.cpp
		algorithms/Level_Order_Traversal.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_SOURCE_DIR}/Utilities")
target_link_directories(${PROJECT_NAME} PUBLIC "${CMAKE_BINARY_DIR}/Utilities")

TARGET_LINK_LIBRARIES(${PROJECT_NAME}
		utils
)