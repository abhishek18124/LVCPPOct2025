#include<iostream>

using namespace std;

void bubbleSort(int arr[], int n) {

	int cnt = 0; // to track no. of comparisions

	for (int i = 1; i <= n - 1; i++) {

		// in the ith pass place the largest element
		// in the unsorted part of the arr[] to its
		// correct position

		bool flag = false; // assume no swaps will be done in the
		// ith pass

		for (int j = 0; j < n - i; j++) {
			cnt++;
			if (arr[j] > arr[j + 1]) {
				flag = true;
				swap(arr[j], arr[j + 1]);
			}
		}

		if (flag == false) {
			// no swaps were done in the ith pass, no need to go to the next pass
			break;
		}

	}

	cout << "cnt = " << cnt << endl;

}

int main() {

	int arr[] = {50, 20, 30, 10, 40};
	int n = sizeof(arr) / sizeof(int);

	bubbleSort(arr, n);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}