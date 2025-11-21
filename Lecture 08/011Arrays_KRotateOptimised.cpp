// 1 <= n <= 100

#include<iostream>

using namespace std;

int main() {

	int arr[] = {10, 20, 30, 40, 50, 60, 70};
	int n = sizeof(arr) / sizeof(int);

	int k = 3;

	k = k % n;

	// 1. reverse the entire array i.e. arr[0...n-1] ~ n/2

	int i = 0;
	int j = n - 1;

	while (i < j) {
		swap(arr[i], arr[j]);
		i++;
		j--;
	}

	// 2. reverse the 1st k elements i.e. arr[0...k-1] ~ k/2

	i = 0;
	j = k - 1;

	while (i < j) {
		swap(arr[i], arr[j]);
		i++;
		j--;
	}

	// 3. reverse the remaining n-k elements i.e. arr[k...n-1] ~ (n-k)/2

	i = k;
	j = n - 1;

	while (i < j) {
		swap(arr[i], arr[j]);
		i++;
		j--;
	}

	// time : n.const ~ O(n)
	// space: O(1)

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}