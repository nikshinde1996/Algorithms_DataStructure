//
// Created by vastu5996 on 29-04-2016.
//
#include <iostream>

#define SIZE 10
using namespace std;

void display(int array[])
{
    for(int i=0;i<SIZE;i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

void max_heapify(int array[], int k, int length)
{
    int left = 2*k+1;
    int right = 2*k+2;
    int largest = k;

    if(left < length && array[left] > array[largest]) largest = left;
    if(right < length && array[right] > array[largest]) largest = right;
    if(largest!=k)
    {
        swap((int *&)array[k], (int*&) array[largest]);
        max_heapify(array,largest,length);
    }
}

void heap_sort(int array[])
{
    for(int i=SIZE/2 -1;i>=0;i--)
        max_heapify(array, i, SIZE);

    for(int i=SIZE-1;i>=0;i--)
    {
        swap((int *&)array[0], (int *&) array[i]);
        max_heapify(array, 0, i);
    }
}

int main()
{
    int array[SIZE] = {1,10,9,7,6,8,5,2,4,3};

    cout << "Unsorted Array: ";
    display(array);

    heap_sort(array);

    cout << "Sorted Array: ";
    display(array);
}
