#include <stdio.h>

void swap (int *x, int *y) {
	int t = *x;
	*x = *y;
	*y = t;
}

void max_heapify (int arr[], int start, int end) {
	int dad = start;
	int son = dad * 2 + 1;
	while (son <= end) {
		if (son + 1 <= end && arr[son] < arr[son + 1])
			son++;
		if (arr[dad] > arr[son])
			return;
		else {
			swap(&arr[dad], &arr[son]);
			dad = son;
			son = dad * 2 + 1;
		}
	}
}

void heap_sort (int arr[], int size) {
	int i;
	for (i = size / 2 - 1; i >= 0; i--)
		max_heapify(arr, i, size - 1);
	for (i = size - 1; i > 0; i--) {
		swap(&arr[0], &arr[i]);
		max_heapify(arr, 0, i - 1);
	}
}

int main() {
	int arr[] = { 22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70 };
	int size = (int)sizeof(arr) / sizeof(*arr);
	heap_sort(arr, size);
	int i;
	for (i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}
