class SelectionSort {
    public static void main(String[] args) {
        int[] array = new int[] { 6, 5, 4, 3, 2, 1 };
        printArray(array);
        selectionSort(array);
        printArray(array);
    }

    public static void selectionSort(int[] array) {
        int index = -1;

        for(int i = 0; i < array.length - 1; i++) {
            int min = array[i];
            for(int j = i + 1; j < array.length; j++) {
                if(array[j] < min) {
                    index = j;
                    min = array[j];
                }
            }
            int temp = array[index];
            array[index] = array[i];
            array[i] = temp;
        }
    }

    private static void printArray(int[] array) {
        System.out.print("Array: ");
        for (int i = 0; i < array.length; i++) {
            System.out.print(array[i] + " ");
        }
        System.out.println();
    }
}