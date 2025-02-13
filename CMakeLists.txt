cmake_minimum_required(VERSION 3.21)
project(Algorithms)

set(CMAKE_CXX_STANDARD 23)

# 5.15 - My home Ubuntu-20.04
if (CMAKE_SYSTEM_VERSION MATCHES "5.15")
    set(THIRD_PARTY_DIR /home/andtokm/DiskS/ProjectsUbuntu/third_party)
    set(EXTRA_LIBS tbb)
else()
    set(THIRD_PARTY_DIR /home/andtokm/Projects/third_party)
endif()

add_subdirectory(Arrays)
add_subdirectory(Graphs)
add_subdirectory(Heaps)
add_subdirectory(Queues)
add_subdirectory(LinkedList)
add_subdirectory(Strings)
add_subdirectory(Stack)
add_subdirectory(Trees)
add_subdirectory(Utilities)
