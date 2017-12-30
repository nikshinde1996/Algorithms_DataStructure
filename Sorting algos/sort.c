#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum sort {
  INSERTION_SORT,
  SELECTION_SORT,
  MERGE_SORT,
  QUICK_SORT
} SORT;

static void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

static void insertion_sort(int *array, int n) {
  int i, j, key;

  for (i = 1; i < n; i++) {
    key = array[i];
    j = i - 1;
    while (j >= 0 && array[j] > key) {
      array[j + 1] = array[j--];
    }
    array[j + 1] = key;
  }
}

static void selection_sort(int *array, int n) {
  int i, j, min;

  for (i = 0; i < n; i++) {
    min = i;
    for (j = i + 1; j < n; j++) {
      if (array[j] < array[min]) {
        min = j;
      }
    }
    swap(&array[i], &array[min]);
  }
}

static void merge(int *array, int start, int mid, int end) {
  int i, j, k, n1, n2;

  n1 = mid - start + 1;
  n2 = end - mid;
  int one[n1], two[n2];

  for (i = 0; i < n1; i++) {
    one[i] = array[start + i];
  }

  for (j = 0; j < n2; j++) {
    two[j] = array[mid + j + 1];
  }

  i = j = 0;
  k = start;
  while (i < n1 && j < n2) {
    if (one[i] <= two[j]) {
      array[k++] = one[i++];
    } else {
      array[k++] = two[j++];
    }
  }

  while (i < n1) {
    array[k++] = one[i++];
  }

  while (j < n2) {
    array[k++] = two[j++];
  }
}

static void merge_sort(int *array, int start, int end) {
  if (start < end) {
    int mid = start + (end - start) / 2;
    merge_sort(array, start, mid);
    merge_sort(array, mid + 1, end);
    merge(array, start, mid, end);
  }
}

static int partition(int *array, int start, int end) {
  int i, j, pivot;

  pivot = array[end];
  i = start - 1;
  for (j = start; j < end; j++) {
    if (array[j] < pivot) {
      swap(&array[++i], &array[j]);
    }
  }
  swap(&array[++i], &array[end]);

  return i;
}

static void quick_sort(int *array, int start, int end) {
  if (start < end) {
    int p = partition(array, start, end);
    quick_sort(array, start, p - 1);
    quick_sort(array, p + 1, end);
  }
}

void sort(int *array, int n, SORT type) {
  switch (type) {
    case INSERTION_SORT:
      insertion_sort(array, n);
      break;
    case SELECTION_SORT:
      selection_sort(array, n);
      break;
    case MERGE_SORT:
      merge_sort(array, 0, n - 1);
      break;
    case QUICK_SORT:
      quick_sort(array, 0, n - 1);
      break;
    default:
      printf("unsupported sort type. exitting ...\n");
      exit(0);
  }
}

static void print_usage() {
  printf("Usage: sort <type> <numbers>\n");
  printf("<type>: insertion, selection, merge, quick\n");
}

SORT type(const char *type) {
  if (strcmp(type, "insertion") == 0) {
    return INSERTION_SORT;
  } else if (strcmp(type, "selection") == 0) {
    return SELECTION_SORT;
  } else if (strcmp(type, "merge") == 0) {
    return MERGE_SORT;
  } else if (strcmp(type, "quick") == 0) {
    return QUICK_SORT;
  } else {
    print_usage();
    exit(0);
  }
}

int main(int argc, char **argv) {
  if (argc < 3) {
    print_usage();
  } else {
    int i, n = argc - 2;
    const char *sort_type = argv[1];
    int array[n];

    for (i = 0; i < n; i++) {
      array[i] = atoi(argv[i + 2]);
    }

    sort(array, n, type(sort_type));

    printf("sort type: %s sort\n", sort_type);
    for (i = 0; i < n; i++) {
      printf("%d ", array[i]);
    }

    printf("\n");
  }
}
