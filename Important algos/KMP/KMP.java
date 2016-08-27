import java.util.*;

class KMP {
	private static String string, pattern;
	private static int[] patternArray;

	public static void main(String args[]) {
		Scanner x = new Scanner(System.in);

		System.out.print("Enter the string: ");
		string = x.nextLine();

		System.out.print("Enter the pattern: ");
		pattern = x.nextLine();

		generatePatternArray();

		if(doKMPSearch()) {
			System.out.println("Pattern exists");
		}
		else {
			System.out.println("Pattern doesn't exists");
		}
	}

	private static void generatePatternArray() {
		int patternLength = pattern.length();
		int j=0, i = 1;
		patternArray = new int[patternLength];

		while(i<patternLength) {
			if(pattern.charAt(i)==pattern.charAt(j)) {
				patternArray[i] = j + 1;
				j++;
				i++;
			}
			else {
				if(j==0) {
					patternArray[i] = 0;
					i++;
				}
				else {
					j = patternArray[j-1];
				}
			}
		}
	}

	private static boolean doKMPSearch() {
		int i=0, j=0;

		while(i<string.length() && j<pattern.length()) {
			if(string.charAt(i)==pattern.charAt(j)) {
				i++;
				j++;
			}
			else {
				if(j!=0) 
					j = patternArray[j-1];
				else 
					i++;
			}
		} 
		
		if(j==pattern.length()) 
			return true;

		else 
			return false;
	}
}