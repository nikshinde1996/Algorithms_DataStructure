//
// Created by nikhi on 08-04-2016.
//

#include <iostream>
#include <iomanip>
#include <cmath>
#include <list>
#include <algorithm>

using namespace std;

template<class T> class Bucket_sort{
public:
    list<T> *bucket;
    int divider;
    Bucket_sort(){
        bucket = new list<T>[10];
    }

    void evaluate(T arr[],T maxi,int size){
       divider = (int)ceil((maxi+1)/10);

       for(int i=0;i<size;i++){
           int factor = (int) floor(arr[i]/divider);
           bucket[factor].push_back(arr[i]);
       }

       for(int i=0;i<10;i++){
           if(!bucket[i].empty()){
               bucket[i].sort();
           }
       }

        cout<<"The Sorted array is : ";
       for(int i=0;i<10;i++){
           if(!bucket[i].empty()){
               for(int j=0;j<bucket[i].size();j++){
                   cout<<bucket[i].front()<<" ";
               }
           }
       }
    }
};

int main(){
    int size,maxi = 0;
    cout<<"Enter the number of elements : ";cin>>size;
    double arr[size];
    cout<<"Enter the elements of the array : "<<endl;
    for(int i=0;i<size;i++){
      cin>>arr[i];
        if(arr[i] > maxi){
            maxi = arr[i];
        }
    }

    Bucket_sort<double> bs;
    bs.evaluate(arr,maxi,size);
    return 0;
}

