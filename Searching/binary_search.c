#include <stdio.h>

#define LENGTH(a) (sizeof(a))/ (sizeof(a[0]))

int binary_search(int target, int *array, int length)
{
    int m, low, high;

    low = 0;
    high = length - 1;
    while(low <= high) {
        m = (low + high) / 2;
        if(target == array[m])
            return m + 1;
        else if(target > array[m])
            low = m + 1;
        else
            high = m - 1;
    }

    return -1;
}

int main(void)
{

    int pos, len, target;
    int array[] = {0, 5, 13, 19, 22, 41, 55, 68, 72, 81, 98};
    
    len = LENGTH(array);
    target = 68;
    pos = binary_search(target, array, len);
    if(pos == -1)
        printf("element %d not found\n", target);
    else
        printf("element %d found at %d\n", target, pos);

    return 0;
}