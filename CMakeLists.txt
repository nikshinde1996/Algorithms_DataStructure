cmake_minimum_required(VERSION 3.5)
project(Algorithms_DataStructure)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        Heap/MaxHeap_Array/MaxHeap_Array_Main.cpp
        Heap/MinHeap_Array/MinHeap_Array.h
        Heap/MinHeap_Array/MinHeap_Array_Main.cpp
        Heap/MaxHeap_Array/MaxHeap_Array.h

        Sorting algos/Quick_sort/quick_sort.cpp
        Sorting algos/Selection_sort/selection_sort.cpp
        Sorting algos/Insertion_sort/insertion_sort.cpp
        Sorting algos/Bubble_sort/bubble_sort.cpp
        Sorting algos/Heap_sort/heap_sort.cpp
        Sorting algos/Counting_sort/counting_sort.cpp
        Sorting algos/Merge_sort/merge_sort.cpp

        Stack/stack_linkedList.cpp

        Queue/Priority Queue/Priority_queue_LinkedList.cpp
        Queue/PriorityQueue_BST/PriorityQueue_BST_Main.cpp
        Queue/queue_LinkedList.cpp
        Queue/Queue cpp/queue_LinkedList.cpp
        Queue/Dequeue/Dequeue.cpp

        Tree/BinarySearchTree.cpp

        Linked List/Linked List cpp/LinkedList.cpp
        )

add_executable(PriorityQueueBST "Queue/PriorityQueue_BST/PriorityQueue_BST_Main.cpp")
add_executable(PriorityQueueLL "Queue/PriorityQueue_LinkedList/Priority_queue_LinkedList.cpp")
add_executable(LinkedList "Linked List/Linked List cpp/LinkedList.cpp")
add_executable(Dequeue "Queue/Dequeue/Dequeue.cpp")
add_executable(BST "Tree/BinarySearchTree.cpp")
add_executable(Queue_dynamic "Queue/queue_LinkedList.cpp")
add_executable(Stack_dynamic "Stack/stack_linkedList.cpp")
add_executable(Quick_sort "Sorting algos/Quick_sort/quick_sort.cpp")
add_executable(Counting_sort "Sorting algos/Counting_sort/counting_sort.cpp")
add_executable(Merge_Sorting "Sorting algos/Merge_sort/merge_sort.cpp")
add_executable(Selection_sort "Sorting algos/Selection_sort/selection_sort.cpp")
add_executable(Insertion_sort "Sorting algos/Insertion_sort/insertion_sort.cpp")
add_executable(Bubble_sort "Sorting algos/Bubble_sort/bubble_sort.cpp")
add_executable(Heap_sort "Sorting algos/Heap_sort/heap_sort.cpp")
add_executable(MaxHeapArray Heap/MaxHeap_Array/MaxHeap_Array_Main.cpp)
add_executable(MinHeapArray Heap/MinHeap_Array/MinHeap_Array_Main.cpp)
