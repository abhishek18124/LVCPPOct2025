#include<iostream>
#include<algorithm>

using namespace std;

int main() {

	int arr[] = {10, 10, 20, 30, 30, 30, 40, 40, 50}; // arr[] is sorted
	int n = sizeof(arr) / sizeof(int);

	// arr[] should sorted to use the following functions

	int key = 50;

	// 1. searching for a key in a sorted sequence in O(logn) using binary_search()

	// bool ans = binary_search(arr, arr + n, key);
	// if (ans) {
	// 	cout << key << " found" << endl;
	// } else {
	// 	cout << key << " not found" << endl;
	// }

	binary_search(arr, arr + n, key) ? cout << key << " found" << endl : cout << key << " not found" << endl;

	// 2. finding lower bound for a key in a sorted sequence in O(logn) using lower_bound()

	key = 30;

	// lower_bound(start, stop, key) return the addr of the 1st element not < key i.e. 1st element >= key

	cout << lower_bound(arr, arr + n, key) - arr << endl;

	// 3. finding upper bound for a key in a sorted sequence in O(logn) using upper_bound()

	// upper_bound(start, stop, key) returns the addr of the 1st element > key

	cout << upper_bound(arr, arr + n, key) - arr << endl;

	// 4. counting the occurences of a key in a sorted sequence in O(logn)

	cout << upper_bound(arr, arr + n, key) - lower_bound(arr, arr + n, key) << endl;

	return 0;
}