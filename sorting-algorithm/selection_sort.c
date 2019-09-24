#include <stdio.h>
void selection_sort(int *arr, int size) {
	int i, j, min, temp;
	for (i = 0; i < size - 1; i++) {
		min = i;
		for (j = i + 1; j < size - 1; j++) {
			if (arr[j] < arr[min]) {
				min = j;
			}
		}
		temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
	}
}

int main() {
	int arr[] = {22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70};
	int size = (int)sizeof(arr) / sizeof(*arr);
	selection_sort(arr, size);
	int i;
	for (i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}
