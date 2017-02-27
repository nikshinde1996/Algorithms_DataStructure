class BubbleSort {
    public static void main(String[] args) {
        int array[] = new int[] {6, 5, 4, 3, 2, 1};
        printArray(array);
        bubbleSort(array);
        printArray(array);
    }

    public static void bubbleSort(int[] array) {
        for(int i = 0; i < array.length; i++) {
            boolean swapped = false;
            for(int j = 0; j < array.length-i-1; j++) {
                if(array[j] > array[j+1]) {
                    int temp = array[j];
                    array[j] = array[j+1];
                    array[j+1] = temp;
                    swapped = true;
                }
            }
            if(!swapped) {
                break;
            }
        }
    }

    private static void printArray(int[] array) {
        System.out.print("Array: ");
        for(int i = 0; i < array.length; i++) {
            System.out.print(array[i] + " ");
        }
        System.out.println();
    } 
}