#include <stdio.h>
void shell_sort(int *arr, int size) {
	int gap, i, j;
	int temp;
	for (gap = size >> 1; gap > 0; gap >>= 1) {
		for (i = gap; i < size; i++) {
			temp = arr[i];
			for (j = i - gap; j >= 0 & arr[j] > temp; j -= gap)
				arr[j + gap] = arr[j];
			arr[j + gap] = temp;
		}
	}
}

int main() {
	int arr[] = { 22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70 };
	int size = (int)sizeof(arr) / sizeof(*arr);
	shell_sort(arr, size);
	int i;
	for (i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}
