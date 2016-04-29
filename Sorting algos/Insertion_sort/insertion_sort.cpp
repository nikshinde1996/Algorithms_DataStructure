//
// Created by nikhi on २९-०४-२०१६.
//
#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

template <typename T> void insertion_sort(T arr[],int n){
    T value;
    int hole;
    for(int i=1;i<n;i++){
        value = arr[i];
        hole = i;
        while(arr[hole-1]>value && hole>0){
            arr[hole] = arr[hole-1];
            hole--;
        }
        arr[hole]=value;
    }
}

int main(){
    int int_arr[] = {6,5,4,3,2};
    float float_arr[] = {6.43,5.343,7.232,3.454,1.567,0.565};
    insertion_sort(int_arr,5);
    insertion_sort(float_arr,6);

    cout<<"Sorted array is :"<<endl;
    for(int i=0;i<6;i++){
        cout<<float_arr[i]<<" ";
    }

}
