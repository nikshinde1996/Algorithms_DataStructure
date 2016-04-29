cmake_minimum_required(VERSION 3.5)
project(Algorithms_DataStructure)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Heap/MaxHeap_Array/MaxHeap_Array_Main.cpp Heap/MinHeap_Array/MinHeap_Array.h Heap/MinHeap_Array/MinHeap_Array_Main.cpp Heap/MaxHeap_Array/MaxHeap_Array.h)

add_executable(MaxHeapArray Heap/MaxHeap_Array/MaxHeap_Array_Main.cpp)
add_executable(MinHeapArray Heap/MinHeap_Array/MinHeap_Array_Main.cpp)
add_executable(Algorithms_DataStructure ${SOURCE_FILES})