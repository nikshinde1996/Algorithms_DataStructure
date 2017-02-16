#include <stdio.h>

#define SIZE(a) (sizeof(a))/(sizeof(a[0]))

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertion_sort(int *a, int n)
{
    int i, j, min, index;

    for(i = 0; i < n-1; i++) {
        min = i;
        for(j = i+1; j < n; j++)
            if(*(a+j) < *(a+min))
                min = j;
        swap((a+i), (a+min));
    }
}

void print_array(int *array, int n) {
    int i, x;

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