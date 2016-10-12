#include<bits/stdc++.h>

using namespace std;

/**
  *   Coin change is the classic dynamic problem in which we have to get the 
  *   change for N using the n number of coins c1,c2...cn 
  *   Assumption : Infinite number of coins as available
  *   We have to find the number of ways in which we can obtain the change for '
  *   using the available c's.
  */ 

int coinChange(int c[],int n,int sum) {
	int dp[n+1][sum+1];
	for(int i=0;i<=sum;i++) { dp[0][i] = 0; }
	for(int i=0;i<=n;i++){ dp[i][0] = 1; }
	
	/*
	    This function is much similar to that of muliple Knapsack problem 
	 */
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=sum;j++) {
	       if(c[i-1]<=j){
	       	  dp[i][j] = dp[i-1][j] + dp[i][j-c[i-1]];
		   }else {
		   	  dp[i][j] = dp[i-1][j];
		   }		
		}
	}
	return dp[n][sum];
}


int coinChange_(int c[],int n,int sum) {
	if(sum==0)
	   return 1;
	if(sum<0){
	   return 0;	
	} 
	if(n<=0 && sum>=1) {
	   return 0;
	}  
	return coinChange_(c,n-1,sum) + coinChange_(c,n,sum-c[n-1]);
}

int main() {
   int val[] = {1,5,8,9};
   cout<<coinChange(val,sizeof(val)/sizeof(val[0]),10)<<endl;   	
   cout<<coinChange_(val,sizeof(val)/sizeof(val[0]),10)<<endl;
return 0;	
}
