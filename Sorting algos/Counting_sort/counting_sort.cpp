//
// Created by nikhi on २९-०४-२०१६.
//

// This sorting technique is explicitly used only for the integers

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>

using namespace std;

template <typename T> void counting_sort(T arr[],int n,int maximum){
   T C[100]={0};
   T arr_sort[n];
   for(int i=0;i<n;i++){
       C[arr[i]]++;
   }

   for(int i=1;i<maximum+1;i++){
       C[i] = C[i] + C[i-1];
   }

   for(int i=0;i<n;i++){
       arr_sort[C[arr[i]]-1] = arr[i];
       --C[arr[i]];
   }

   for(int i=0;i<n;i++){
       cout<<arr_sort[i]<<" ";
   }
}

int main(){
    int arr[10] = {9,7,5,3,2,2,1,8,6,5};
    counting_sort(arr,10,9);
    return 0;
}

