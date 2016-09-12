import java.util.*;

class Knapsack {
	private static int[] value, weight;
	private static int totalWeight = 7;

	public static void main(String args[]) {
		Scanner x = new Scanner(System.in);

		value = new int[] {1,4,5,7};
		weight = new int[] {1,3,4,5};
		
		System.out.println("Recursive Soln: " + recKnapSack(totalWeight, value.length));
		System.out.println("DP Soln: " + knapSack());
	}

	private static int recKnapSack(int w, int n) {
		if(n==0||w==0)
			return 0;
		if(weight[n-1]>w)
			return recKnapSack(w, n-1);
		else
			return Math.max(value[n-1] + recKnapSack(w-weight[n-1],n-1), recKnapSack(w,n-1));
	}

	private static int knapSack() {
		int dp[][] = new int[value.length+1][totalWeight+1];

		for(int i=0;i<=value.length;i++) {
			for(int j=0;j<=totalWeight;j++) {
				if(i==0 || j==0) 
					dp[i][j] = 0;
				else if(weight[i-1]<=j)
					dp[i][j] = Math.max(value[i-1] + dp[i-1][j-weight[i-1]], dp[i-1][j]);
				else
					dp[i][j] = dp[i-1][j];
			}
		}

		return dp[value.length][totalWeight];
	}
}