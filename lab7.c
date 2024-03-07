#include <stdio.h>

void swap(int *xp, int *yp, int *swaps) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
    (*swaps)++;
}

void bubbleSort(int arr[], int n, int *total_swaps, int swaps[]) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1], &swaps[arr[j]]);
                (*total_swaps)++;
            }
        }
    }
}

void selectionSort(int arr[], int n, int *total_swaps, int swaps[]) {
    int i, j, min_idx;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        if (min_idx != i) {
            swap(&arr[min_idx], &arr[i], &swaps[arr[min_idx]]);
            (*total_swaps)++;
        }
    }
}

int main() {
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int n1 = sizeof(array1)/sizeof(array1[0]);
    int n2 = sizeof(array2)/sizeof(array2[0]);
    int total_bubble_swaps1 = 0, total_bubble_swaps2 = 0;
    int total_selection_swaps1 = 0, total_selection_swaps2 = 0;
    int bubble_swaps1[100] = {0}, bubble_swaps2[100] = {0};
    int selection_swaps1[100] = {0}, selection_swaps2[100] = {0};

    int array1_copy[n1], array2_copy[n2];
    for (int i = 0; i < n1; i++)
        array1_copy[i] = array1[i];
    for (int i = 0; i < n2; i++)
        array2_copy[i] = array2[i];

    bubbleSort(array1, n1, &total_bubble_swaps1, bubble_swaps1);
    bubbleSort(array2, n2, &total_bubble_swaps2, bubble_swaps2);

    printf("Bubble Sort:\n");
    printf("Array1:\n");
    for (int i = 0; i < n1; i++)
        printf("%d: %d times\n", array1[i], bubble_swaps1[array1[i]]);
    printf("Total swaps in array1: %d\n", total_bubble_swaps1);

    printf("Array2:\n");
    for (int i = 0; i < n2; i++)
        printf("%d: %d times\n", array2[i], bubble_swaps2[array2[i]]);
    printf("Total swaps in array2: %d\n", total_bubble_swaps2);

    selectionSort(array1_copy, n1, &total_selection_swaps1, selection_swaps1);
    selectionSort(array2_copy, n2, &total_selection_swaps2, selection_swaps2);

    printf("Selection Sort:\n");
    printf("Array1:\n");
    for (int i = 0; i < n1; i++)
        printf("%d: %d times\n", array1_copy[i], selection_swaps1[array1_copy[i]]);
    printf("Total swaps in array1: %d\n", total_selection_swaps1);

    printf("Array2:\n");
    for (int i = 0; i < n2; i++)
        printf("%d: %d times\n", array2_copy[i], selection_swaps2[array2_copy[i]]);
    printf("Total swaps in array2: %d\n", total_selection_swaps2);

    return 0;
}
