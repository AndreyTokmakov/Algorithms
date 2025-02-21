cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

project(LinkedList)
set(PROJECT_VERSION 1.0.0.0)
project(${PROJECT_NAME} VERSION ${PROJECT_VERSION} LANGUAGES CXX)

add_compile_options(-c -Wall -Wextra -O3 -std=c++23)

add_executable(${PROJECT_NAME}
    	main.cpp
    	common.h
		LinkedListAlgorithms.h
    	algorithms/Other.cpp
    	algorithms/Check_List_Is_Cycled.cpp
    	algorithms/Reverse_List.cpp
    	algorithms/Check_If_Palindrome.cpp
    	algorithms/Find_Nth_Element_FromTheEnd.cpp
    	algorithms/Remove_N_Node_From_End.cpp
    	algorithms/Merge_Two_Lists.cpp
		algorithms/Insert_Into_Sorted_List.cpp
		algorithms/Delete_Nodes_By_Value.cpp
		algorithms/Delete_Node_By_Position.cpp
		algorithms/Get_Length.cpp
		algorithms/Find_Middle_Element.cpp
		algorithms/Delete_Duplicates.cpp
		algorithms/Move_All_Occurrences_To_The_End.cpp
		algorithms/Delete_K_Element_From_the_End.cpp
		algorithms/Delete_Duplicates_SortedList.cpp
		algorithms/Add_Two_Numbers.cpp
		algorithms/Merge_K_Sorter_Lists.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_SOURCE_DIR}/Utilities")
target_link_directories(${PROJECT_NAME} PUBLIC "${CMAKE_BINARY_DIR}/Utilities")

TARGET_LINK_LIBRARIES(${PROJECT_NAME}
		utils
)