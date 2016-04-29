//
// Created by nikhi on २९-०४-२०१६.
//
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>

using namespace std;

template <typename T> void Bubble_sort(T arr[],int n){
    T temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(){
    int int_arr[] = {6,5,4,3,2};
    float float_arr[] = {6.43,5.343,7.232,3.454,1.567,0.565};
    Bubble_sort(int_arr,5);
    Bubble_sort(float_arr,6);

    cout<<"Sorted array is :"<<endl;
    for(int i=0;i<6;i++){
        cout<<float_arr[i]<<" ";
    }
    return 0;
}