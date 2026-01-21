// constraints : n <= 100

#include<iostream>

using namespace std;

void merge(int arr[], int s, int m, int e) {

	int i = s;
	int j = m + 1;
	int k = s;

	int temp[100]; // based on constraints

	while (i <= m and j <= e) {

		if (arr[i] <= arr[j]) {
			temp[k] = arr[i];
			i++;
			k++;
		} else {
			temp[k] = arr[j];
			j++;
			k++;
		}

	}

	while (i <= m) {
		temp[k] = arr[i];
		i++;
		k++;
	}

	while (j <= e) {
		temp[k] = arr[j];
		j++;
		k++;
	}

	// temp[s..e] is sorted

	// to make sure arr[s...e] becomes sorted just copy temp[s...e]
	// to arr[s...e]

	for (int x = s; x <= e; x++) {
		arr[x] = temp[x];
	}

}

void f(int arr[], int s, int e) {

	// base case

	if (s == e) {
		// f(s, s) : sort arr[s..s] using merge sort algo.
		return;
	}

	// recursive case

	// f(s, e) : sort the arr[s...e] using the merge sort algo.

	// 1. divide the arr[s...e] around the midPoint

	int m = s + (e - s) / 2;

	// 2. ask your friend to sort arr[s...m] and arr[m+1...e]

	f(arr, s, m);
	f(arr, m + 1, e);

	// 3. merge the two sorted subarrays arr[s...m] and arr[m+1...e]

	merge(arr, s, m, e);

}

int main() {

	int arr[] = {60, 50, 40, 30, 20, 10};
	int n = sizeof(arr) / sizeof(int);

	f(arr, 0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;

}