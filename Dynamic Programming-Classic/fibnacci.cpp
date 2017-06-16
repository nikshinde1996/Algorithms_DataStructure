#include<iostream>
#define MAX 10001

using namespace std;

int dp[MAX];
void _init_(){
    for(int i=0;i<MAX;i++){
        dp[i]=-1;
    }
}

/*Memozation*/
int fib(int n){
    if(dp[n]==-1){
        dp[n] = (n<=1)?n:fib(n-1)+fib(n-2);
    }
    return dp[n];
}

/*Tabulation*/
int Fib(int n){
    int f[n+1];
    f[0]=0,f[1]=1;
    for(int i=2;i<=n;i++){
        f[i]=f[i-1]+f[i-2];
    }
    return f[n];
}

int main(void){
    _init_();
    cout<<fib(7)<<endl;
    cout<<Fib(7)<<endl;
}