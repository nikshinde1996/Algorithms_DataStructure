#include <stdio.h>

#define max(a,b) ((a) > (b) ? (a) : (b))

int knapsack(int w[], int v[], int n, int max) 
{
    int i,j;
    int dp[n+1][max+1];

    for(i=0;i<=n;i++)
    {
        for(j=0;j<=max;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j] = 0;
            }
            else if(w[i-1] <= j)
            {
                dp[i][j] = max(v[i-1] + dp[i-1][j- w[i-1]], dp[i-1][j]);
            }
            else 
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][max];
}

int main()
{
    int n = 4, max_value = 7;
    int weight[] = {1,3,4,5};
    int value[] = {1,4,5,7};

    printf("%d\n",knapsack(weight,value,n,max_value));
}