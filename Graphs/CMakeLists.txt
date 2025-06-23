cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

project(Graphs)
set(PROJECT_VERSION 1.0.0.0)
project(${PROJECT_NAME} VERSION ${PROJECT_VERSION} LANGUAGES CXX)

add_compile_options(-c -Wall -Wextra -O3 -std=c++23)

add_executable(${PROJECT_NAME}
    	main.cpp
		algorithms/Other.cpp
		algorithms/BFS.cpp
		algorithms/DFS.cpp
		algorithms/DFS_NonRecur.cpp
		algorithms/Detect_Cycle.cpp
		algorithms/Detect_Cycle_2.cpp
		algorithms/Find_Shortest_Path.cpp
		algorithms/Find_Shortest_Path_1.cpp
		algorithms/Find_Shortest_Path_Dijkstra.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_SOURCE_DIR}/Utilities")
target_link_directories(${PROJECT_NAME} PUBLIC "${CMAKE_BINARY_DIR}/Utilities")

TARGET_LINK_LIBRARIES(${PROJECT_NAME}
		utils
)