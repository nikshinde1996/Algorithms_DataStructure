//
// Created by nikhi on 06-04-2016.
//

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <list>
#include <string>

using namespace std;

template<typename T> class Radix_sort{

public:
    list<int> *bucket;
    Radix_sort(){
        bucket = new list<int>[10];
    }

    void evaluate(){

    }
};

string append(string x,int len){
    for(int i=1;i<=len;i++){
        x = "0" + x;
    }
    return x;
}

int main(){
    Radix_sort<int> rs;
    int n,max_len=0;
    cout<<"Enter the number of elements : ";
    cin>>n;
    string nums[n];
    cout<<"Enter the elements to sort : "<<endl;
    for(int i=0;i<n;i++){
      cin>>nums[i];
      if(nums[i].length() > max_len){max_len = nums[i].length();}
    }

    for(int i=0;i<n;i++){ append(nums[i],max_len); }

    return 0;
}
