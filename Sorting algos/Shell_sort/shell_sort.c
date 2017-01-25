#include <stdio.h>
#define LENGTH(a) (sizeof a) / (sizeof a[0])

int main(void)
{
	int i;
	int array[] = {6, 5, 4, 3, 2, 1};
	void shell_sort(int *array, int length);

	shell_sort(array, LENGTH(array));
	for(i = 0; i < LENGTH(array); i++)
		printf("%d ", *(array+i));
	printf("\n");
	return 0;
}

void shell_sort(int *a, int length)
{
	int i, j, gap, temp;

	gap = length / 2;
	while(gap > 0) {
		for(i = gap; i < length; i++) {
			temp = *(a+i);
			for(j = i; j >= gap && *(a+j-gap) > temp; j -= gap)
				*(a+j) = *(a+j-gap);
			*(a+j) = temp;
		}
		gap /= 2;
	}
}
