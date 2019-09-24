#include <stdio.h>
#include <stdlib.h>

int min(int x, int y) {
    return x < y ? x : y;
}
void merge_sort(int arr[], int len) {
    int *a = arr;
    int *b = (int *) malloc(len * sizeof(int));
    int seg, start;
    for (seg = 1; seg < len; seg += seg) {
        for (start = 0; start < len; start += seg * 2) {
            int low = start, mid = min(start + seg, len), high = min(start + seg * 2, len);
            int k = low;
            int start1 = low, end1 = mid;
            int start2 = mid, end2 = high;
            while (start1 < end1 && start2 < end2)
                b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
            while (start1 < end1)
                b[k++] = a[start1++];
            while (start2 < end2)
                b[k++] = a[start2++];
        }
        int *temp = a;
        a = b;
        b = temp;
    }
    if (a != arr) {
        int i;
        for (i = 0; i < len; i++)
            b[i] = a[i];
        b = a;
    }
    free(b);
}

// recursive implement
// void merge_sort_recursive(int arr[], int reg[], int start, int end) {
//     if (start >= end)
//         return;
//     int len = end - start, mid = (len >> 1) + start;
//     int start1 = start, end1 = mid;
//     int start2 = mid + 1, end2 = end;
//     merge_sort_recursive(arr, reg, start1, end1);
//     merge_sort_recursive(arr, reg, start2, end2);
//     int k = start;
//     while (start1 <= end1 && start2 <= end2)
//         reg[k++] = arr[start1] < arr[start2] ? arr[start1++] : arr[start2++];
//     while (start1 <= end1)
//         reg[k++] = arr[start1++];
//     while (start2 <= end2)
//         reg[k++] = arr[start2++];
//     for (k = start; k <= end; k++)
//         arr[k] = reg[k];
// }

// void merge_sort(int arr[], const int len) {
//     int reg[len];
//     merge_sort_recursive(arr, reg, 0, len - 1);
// }

int main() {
    int arr[] = { 22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70 };
    int size = (int)sizeof(arr) / sizeof(*arr);
    merge_sort(arr, size);
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}

//result 
//3 5 9 22 32 34 35 37 50 55 64 70 82 89
