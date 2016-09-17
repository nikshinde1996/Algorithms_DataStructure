/*
 *   Given weights and values of the items...we have to put these items in the knapsack of capacity W to get maximum
 *   total value and weights to max limit. In 0-1 and multiple we arent allowed to break the item but here we can break the item 
 */ 

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void knapsack(float value[],float weight[],float max,float n) { 
    float current=0,rem;
    float currentval=0;
    int i = 0;
	 
	while((current<=max) && (weight[i]<=max-current)) { 
	    current = current + weight[i];
        currentval = currentval + value[i];
        i++;
    }
        rem = max - current;
    if(current < max) {
	   current = current + rem;
       currentval = currentval + ((rem * value[i])/weight[i] );
    }

    cout<<"\n\nmaximum profit is: "<<currentval;
    cout<<"\ncurrent weight is: "<<current;
}

int main() {
	float W = 10;
	float n = 3;
	float wt[] = {2,3,4};
	float val[] = {4,3,6};
    
	knapsack(val,wt,W,n);
}
