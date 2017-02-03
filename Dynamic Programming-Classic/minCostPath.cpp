#include<bits/stdc++.h>
#define R 3
#define C 3

using namespace std;

/**
    Given matrix cost[][] and final position find the min cost of travelling from (0,0) to (m,n)
*/
int minCost(int arr[R][C],int m,int n){
    int dp[R][C]={0};
    dp[0][0] = arr[0][0];

    for(int i=0;i<R;i++){
      for(int j=0;j<C;j++){
         if(i==0 && j!=0){
           dp[i][j] = arr[i][j] + dp[i][j-1];
         }else if(j==0 && i!=0){
           dp[i][j] = arr[i][j] + dp[i-1][j];
         }else{
           dp[i][j] = arr[i][j] + min(dp[i][j-1],min(dp[i-1][j-1],dp[i-1][j]));
         }
         cout<<std::setw(4)<<dp[i][j];
      }
      cout<<endl;
    }
    return dp[m][n];
}

int main(){
   int arr[3][3] = {{1,2,3},
                    {4,8,2},
                    {1,5,3}};
   cout<<minCost(arr,2,2)<<endl;
}
