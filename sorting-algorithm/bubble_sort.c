#include <stdio.h>
void bubble_sort(int *arr, int size) {
	int i, j, temp;
	int flag = 0;
	for (i = 0; i < size - 1; i++) {
		flag = 0;
		for (j = 0; j < size - i - 1; j++){
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				flag = 1;
			}
		}
		if (flag == 0) {
			break;
		}
	} 
}

int main() {
	int arr[] = {22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70};
	int size = (int)sizeof(arr) / sizeof(*arr);
	bubble_sort(arr, size);
	int i;
	for (i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}
