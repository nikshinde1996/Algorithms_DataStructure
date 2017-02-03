#include<bits/stdc++.h>

using namespace std;

int longestSubSequence(int arr[],int n){
    int len = 0;
    int dp[n];
    for(int i=0;i<n;i++)dp[i]=1;

    for(int i=1 ;i<n;i++){
       if(arr[i]>arr[i-1]){
         dp[i] = max(dp[i-1]+1,dp[i]);
       }else{
         dp[i] = dp[i-1];
       }
    }
    // for(int i=0;i<n;i++) cout<<dp[i]<<" ";
    return *std::max_element(dp,dp+n);
}

int main(){
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60};
    cout<<longestSubSequence(arr,sizeof(arr)/sizeof(arr[0]))<<endl;
}
