#include<iostream>

using namespace std;

void modify(int arr[], int n) { // arr[] is by default passed by ref so changes done to the arr[] within the fn will be reflected in the caller fn
	for (int i = 0; i < n; i++) {
		arr[i]++;
	}
}

int main() {

	int arr[] = {10, 20, 30, 40, 50};
	int n = sizeof(arr) / sizeof(int);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl; // 10 20 30 40 50

	modify(arr, n);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl; // 11 21 31 41 51

	return 0;
}