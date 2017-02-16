#include <stdio.h>

#define SIZE(a) (sizeof(a))/(sizeof(a[0]))

void insertion_sort(int *array, int n)
{
    int i, j, key;

    for(i = 1; i < n; i++) {
        key = *(array+i);
        j = i - 1;
        while(j >= 0 && key < *(array+j)) {
            *(array+j+1) = *(array+j);
            j--;
        }
        *(array+j+1) = key;
    }
}

void print_array(int *array, int n)
{
    int i;

    printf("Array: ");
    for(i = 0; i < n; i++)
        printf("%d ", *(array+i));
    printf("\n");
}

int main(void)
{
    int array[] = {6, 5, 4, 3, 2, 1};
    int n = SIZE(array);

    print_array(array, n);
    insertion_sort(array, n);
    print_array(array, n);

    return 0;
}