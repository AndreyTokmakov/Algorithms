cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

project(LinkedList)
set(PROJECT_VERSION 1.0.0.0)
project(${PROJECT_NAME} VERSION ${PROJECT_VERSION} LANGUAGES CXX)

add_compile_options(-c -Wall -Wextra -O3 -std=c++26)

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
)

target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_SOURCE_DIR}/Utilities")
target_link_directories(${PROJECT_NAME} PUBLIC "${CMAKE_BINARY_DIR}/Utilities")

TARGET_LINK_LIBRARIES(${PROJECT_NAME}
		utils
)