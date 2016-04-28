cmake_minimum_required(VERSION 3.5)
project(Algorithms_DataStructure)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Queue/PriorityQueue_BST/PriorityQueue_BST.h Queue/PriorityQueue_BST/PriorityQueue_BST_Main.cpp)
add_executable(PriorityQueueBST Queue/PriorityQueue_BST/PriorityQueue_BST_Main.cpp)
add_executable(Algorithms_DataStructure ${SOURCE_FILES})