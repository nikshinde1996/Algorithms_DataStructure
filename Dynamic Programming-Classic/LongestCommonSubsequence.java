import java.io.*;
import java.util.*;

public class LongestCommonSubsequence{

    static int tabulation_lcs(String X,String Y){
        int lenX = X.length();
        int lenY = X.length();

        int dp[][] = new int[lenX+1][lenY+1];
        for(int i=0;i<=lenX;i++){
            for(int j=0;j<=lenY;j++){
                if(i==0 || j==0){
                    dp[i][j]=0;
                }
                else if(X.charAt(i-1)==Y.charAt(j-1)){
                    dp[i][j]=dp[i-1][j-1]+1; 
                }
                else{
                    dp[i][j]=Math.max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[lenX][lenY];
    }

    static int memoization_lcs(String X,String Y,int lenX,int lenY){

        if(lenX==0 || lenY==0){
            return 0;
        }
        else if(X.charAt(lenX-1)==Y.charAt(lenY-1)){
            return memoization_lcs(X,Y,lenX-1,lenY-1)+1;
        }    
        else{
            return Math.max(memoization_lcs(X,Y,lenX,lenY-1),memoization_lcs(X,Y,lenX-1,lenY));
        }
    }

    public static void main(String args[]){
        System.out.println(tabulation_lcs("testtest","easttemt"));
        System.out.println(memoization_lcs("testtest","easttemt","testtest".length(),"easttemt".length()));
    }
}