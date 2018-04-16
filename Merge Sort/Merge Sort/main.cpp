#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int low, int mid, int high) {
	
	int *out = (int*)malloc(sizeof(int) * (high - low + 1));

	int indLeft = low;
	int indRight = mid + 1;
	int indOut = 0;

	while (indLeft <= mid && indRight <= high) 
	{
		if (arr[indLeft] > arr[indRight])
			out[indOut++] = arr[indLeft++];
		else
			out[indOut++] = arr[indRight++];
	}

	while (indLeft <= mid) {
		out[indOut++] = arr[indLeft++];
	}
	while (indRight <= high) {
		out[indOut++] = arr[indRight++];
	}

	--indOut;
	while (indOut >= 0) {
		arr[low + indOut] = out[indOut];
		--indOut;
	}

	free(out);
}

void divide(int arr[], int low, int high) {

	// termination
	if (low >= high)
		return;

	// Action
	int mid = (high + low) / 2;
	divide(arr, low, mid);
	divide(arr, mid + 1, high);

	merge(arr, low, mid, high);

	return;
}

int main() {

	int arr[] = { 10, 20, 30, 40, 50, 60 };
	
	divide(arr, 0, sizeof(arr) / sizeof(int) - 1);

	return 0;
}