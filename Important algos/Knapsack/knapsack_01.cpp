#include<iostream>
#include<bits/stdc++.h>
#include<cstdlib>

using namespace std;

int knapsack(int W,int wt[],int val[],int n) {
	int dp[n+1][W+1];
	for(int i=0;i<n+1;i++) {
		for(int j=0;j<=W+1;j++) {
			if(i==0 || w==0) {
				dp[i][w] = 0;
			}else if(wt[i-1] <= w) {
//[if nultiple]	   dp[i][w] = max(dp[i-1][w],val[i-1]+dp[i][w-wt[i-1]]);
            	   dp[i][w] = max(dp[i-1][w],val[i-1]+dp[i-1][w-wt[i-1]]);
			}else {
				dp[i][w] = dp[i-1][w];
			}
		}
	}
	return dp[n][w];
}

int rknapsack(int W,int wt[],int val[],int n) {
   if(n==0 || W==0){
   	  return 0;
   }else if(wt[n-1] <= W){
   	  return max(rknapsack(W,wt,val,n-1),val[n-1]+rknapsack(W-wt[n-1],wt,val,n-1));
   }else {
   	  rknapsack(W,wt,val,n-1);
   }	
}

int main() {
	int n = 3;
	int W = 10;
	int wt[] = {2,3,5};
	int val[] = {5,3,7};
	cout<<knapsack(W,wt,val,n)<<endl;
}
