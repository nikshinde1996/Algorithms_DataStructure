//
// Created by nikhi on ३०-०४-२०१६.
//

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <algorithm>

using namespace std;

template <typename T> void quick_sort(T arr[],int start,int end){
   int pivot,temp,j,i;
    if(start<end){
        pivot = start;
        i = start;
        j = end;

        while(i<j){

            while(arr[i]<=arr[pivot] && i<end)i++;

            while(arr[j]>arr[pivot])j--;

            if(i<j) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        temp = arr[pivot];
        arr[pivot] = arr[j];
        arr[j]=temp;

        quick_sort(arr,start,j-1);
        quick_sort(arr,j+1,end);
    }
}

int main(){
    int i_arr[8] = {12,11,9,7,5,3,1,7};
    quick_sort(i_arr,0,7);

    for(int i=0;i<8;i++){
        cout<<i_arr[i]<<" ";
    }

    return 0;
}
