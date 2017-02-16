#include <stdio.h>

#define SIZE(a) (sizeof(a))/(sizeof(a[0]))
#define TRUE    1
#define FALSE   0

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int *array, int n) {
    int i, j;
    int swapped;

    swapped = FALSE;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(*(array+j) > *(array+j+1)) {
                swap((array+j), (array+j+1));
                swapped = TRUE;
            }
        }
        if(!swapped)
            break;
    }
}

void print_array(int *array, int n) {
    int i, x;

    printf("Array: ");
    for(i = 0; i < n; i++)
        printf("%d ", *(array+i));
    printf("\n");
}

int main()
{
    int array[] = {6, 5, 4, 3, 2, 1};
    void print_array(int*, int);
    void bubble_sort(int *, int);

    int n = SIZE(array);
    print_array(array, n);
    bubble_sort(array, n);
    print_array(array, n);

    return 0;
}