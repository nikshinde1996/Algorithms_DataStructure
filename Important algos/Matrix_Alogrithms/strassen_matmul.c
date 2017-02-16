#include<stdio.h>
#include<stdlib.h>

int strassen2Dmul(){
    int r1,r2,c1,c2;
    r1=r2=c1=c2=2;

    int arr1[r1][c1],arr2[r2][c2],c[r1][c2];

    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            scanf("%d",&arr1[i][j]);
        }
    }

    for(int i=0;i<r2;i++){
        for(int j=0;j<c2;j++){
            scanf("%d",&arr2[i][j]);
        }
    }

    int m1,m2,m3,m4,m5,m6,m7;

    m1 = (arr1[0][0] + arr1[1][1])*(arr2[0][0] + arr2[1][1]);
    m2 = (arr1[1][0] + arr1[1][1])*arr2[0][0];
    m3 = arr1[0][0]*(arr2[0][1] - arr2[1][1]);
    m4 = arr1[1][1]*(arr2[1][0] - arr2[0][0]);
    m5 = (arr1[0][0] + arr1[0][1])*arr2[1][1];
    m6 = (arr1[1][0] - arr1[0][0])*(arr2[0][0] + arr2[0][1]);
    m7 = (arr1[0][1] - arr1[1][1])*(arr2[1][0] + arr2[1][1]);

    c[0][0] = m1 + m4 - m5 + m7;
    c[0][1] = m3 + m5;
    c[1][0] = m2 + m4;
    c[1][1] = m1 - m2 + m3 + m6;

    printf("Matrix obtained from Multiplication : ");
    for(int i=0;i<r1;i++){
        printf("\n");
        for(int j=0;j<c2;j++){
           printf("%d\t",c[i][j]);
        }
    }

}

void strassenNDmul(int r1,int c1,int r2,int c2){

}

int main(){
    strassen2Dmul();
    strassenNDmul();
    return 0;
}



