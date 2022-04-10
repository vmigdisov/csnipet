#include <stdio.h>

void sort(int [], int);
void quick_sort(int *, int, int);

int main() {
	int arr[] = { 2, 4, 1, 9, 7, 5, 6, 3, 9, 3, 8 };
	int n = sizeof(arr) / sizeof(arr[0]);
        sort(arr, n);
        for (int i = 0; i < n; i++) printf("%d ", arr[i]);
	printf("\n");
	return 0;
}


void sort(int arr[], int n) {
	quick_sort(arr, 0, n - 1);
}

void quick_sort(int *arr, int left, int right) {
	int mid = arr[(left + right) / 2]; // any value in [left, right]
	int i = left, j = right;
	do {
		while(arr[i] < mid) i++;
		while(mid < arr[j]) j--;
		if (i <= j) {
			int tmp = arr[i];
			arr[i++] = arr[j];
			arr[j--] = tmp;
		}
	} while (i < j);
	if (left < j) quick_sort(arr, left, j);
	if (i < right) quick_sort(arr, i, right);
}

