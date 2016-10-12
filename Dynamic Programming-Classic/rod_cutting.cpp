#include<bits/stdc++.h>

using namespace std;

/**
  *  Rod cutting is the classic problem in the Dynamic programming in which
  *  The values of all the rods less than the length of rod are given and 
  *  we have to output the maximum value sum we can get after curring the rod 
  *  into different parts.
  */ 


int cutRod(int val[],int n) {
	if(n<=0){
		return 0;
	}
	int max_value = INT_MIN;
	for(int i=0;i<n;i++) {
		max_value = max(max_value,val[i]+cutRod(val,n-i-1));
	}
	return max_value;
}

int main() {	
   int val[] = {1,5,8,9,10,17,17,20};
   cout<<cutRod(val,sizeof(val)/sizeof(val[0]))<<endl;	
return 0;	
}
