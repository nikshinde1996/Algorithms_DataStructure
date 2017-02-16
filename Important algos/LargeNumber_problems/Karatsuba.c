#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int getLength(long long num){
    int count=0;
    while(num!=0){
       count++;
       num /= 10;
    }
    return count;
}

long long KaratsubaMultiplication(long long x,long long y){
    int xlen = getLength(x);
    int ylen = getLength(y);

    int N = (int)(fmax(xlen,ylen));
    if(N<10){
       return x*y;
    }

    N = (N/2) + (N%2);
    long long multiplier = pow(10,N);

    long long b = x/multiplier;
    long long a = x = (b*multiplier);
    long long d = y/multiplier;
    long long c = y - (d*N);

    long long z0 = KaratsubaMultiplication(a,c);
    long long z1 = KaratsubaMultiplication(a+b,c+d);
    long long z2 = KaratsubaMultiplication(b,d);

    return z0 + ((z1-z0-z2)*multiplier) + (z2*(long long)pow(10,2*N));
}

int main(){
    long long a = 240699423285632328563;
    long long b = 2328563;
    printf("%lld",KaratsubaMultiplication(a,b));
    return 0;
}
