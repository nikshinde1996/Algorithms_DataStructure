public class BinarySearch {

	public static int binarySearch(int array[], int target) {
		int length = array.length;
		int low = 0;
		int high = length - 1;
		
		while(low <= high) {
			int m = (low + high) / 2;
			if(target == array[m])
				return m + 1;
			else if(target < array[m])
				high = m - 1;
			else
				low = m + 1;
		}
		
		return -1;
	}
	
	public static void main(String args[]) {
		int array[] = {0, 5, 13, 19, 22, 41, 55, 68, 72, 81, 98};
		int target = 68;
		
		int pos = binarySearch(array, target);
		if(pos == -1)
			System.out.println("element " + target + " not found.");
		else
			System.out.println("element " + target + " found at " + pos + ".");
		
	}
}
