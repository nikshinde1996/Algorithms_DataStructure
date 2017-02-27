class InsertionSort {
    public static void main(String[] args) {
        int[] array = new int[] {6, 5, 4, 3, 2, 1};
        printArray(array);
        insertionSort(array);
        printArray(array);
    }

    public static void insertionSort(int[] array) {
        for(int i = 1; i < array.length; i++) {
            int key = array[i];
            int j = i - 1;
            while(j >= 0 && key < array[j]) {
                array[j+1] = array[j];
                j--;
            }
            array[j+1] = key;
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