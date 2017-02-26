//
// Created by nikhi on २९-०४-२०१६.
//

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

template <typename T> void selection_sort(T arr[],int n){
    T temp;
    int mindex = -1;
    for(int i=0;i<n-1;i++){
        int min_ele = arr[i];
        for(int j=i+1;j<n;j++){
            if(min_ele>arr[j]){
                mindex = j;
                min_ele = arr[j];
            }
        }
        T temp = arr[mindex];
        arr[mindex] = arr[i];
        arr[i] = temp;
    }
}

int main(){
    int int_arr[] = {6,5,4,3,2};
    float float_arr[] = {6.43,5.343,7.232,3.454,1.567,0.565};
    selection_sort(int_arr,5);
    selection_sort(float_arr,6);

    cout<<"Sorted array is :"<<endl;
    for(int i=0;i<6;i++){
        cout<<float_arr[i]<<" ";
    }

}
