//
// Created by nikhi on २९-०४-२०१६.
//

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>

using namespace std;

template <typename T> void merge(T arr[],int start,int mid,int end){
    T temp[100];
    int j = start,m = mid+1;
    int i,k;
    for(i = start;j<=mid && m<= end;i++){
        if(arr[j]<arr[m]){
            temp[i] = arr[j];
            j++;
        }else{
            temp[i] =  arr[m];
            m++;
        }
    }
    if(j>mid){
        for(k = m;k<=end;k++){
            temp[i] = arr[k];
            i++;
        }
    }else{
        for(k = j;k<=mid;k++){
            temp[i] = arr[k];
            i++;
        }
    }
    for(k = start;k<=end;k++){
           arr[k] = temp[k];
    }
}

template <typename T> void merge_sort(T arr[],int end,int start){
    int mid = (start+end)/2;
    if(start<end){
        merge_sort(arr,start,mid);
        merge_sort(arr ,mid+1,end);
        merge(arr,start,mid,end);
    }
}

int main(){
    int arr[8] = {9,8,5,3,7,4,2,1};

    merge_sort(arr,0,7);

    for(int i=0;i<8;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
