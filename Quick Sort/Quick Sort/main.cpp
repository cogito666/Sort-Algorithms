#include <stdio.h>

// pivot value = right most
// Algorithm
// 1) select one pivot.
// 2) make pivot partition dividing elements less and bigger that itself.
// 3) repeat process 1), 2) for divided list until the size of it is 0 or 1.
int partition(int arr[], int low, int high, int pivotIndex) 
{
	// put pivot at last
	int tmp = arr[high];
	arr[high] = arr[pivotIndex];
	arr[pivotIndex] = tmp;

	int storeInd = low;
	int pivotVal = arr[high];

	for (int i = low; i <= high - 1; ++i) {
		if (arr[i] >= pivotVal) {
			int tmp = arr[i];
			arr[i] = arr[storeInd];
			arr[storeInd] = tmp;
			
			++storeInd;
		}
	}

	// swap value of storeInd with one of Last
	//printf("Put Pivot Value between two list\n");
	arr[high] = arr[storeInd];
	arr[storeInd] = pivotVal;

	return storeInd;
}

void quickSort(int arr[], int low, int high) {

	// termination
	if (!(high > low))
		return;

	int indPivot = partition(arr, low, high, (low + high) / 2);

	quickSort(arr, low, indPivot - 1);
	quickSort(arr, indPivot + 1, high);

	return;
}

int main() {

	int arr[] = { 1, 2, 3, 4, 5 };
	quickSort(arr, 0, sizeof(arr) / sizeof(int) - 1);


	for (int i = 0; i < 5; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}