#include<iostream>

using namespace std;

// time : O(logn)

int f1(int arr[], int n, int t) {

	int s = 0;
	int e = n - 1;

	int ans = -1;

	while (s <= e) {

		int m = s + (e - s) / 2;
		if (arr[m] == t) {
			ans = m;
			// now, look for more occurrences of 't' towards the
			// left of the 'm' i.e. reduce the search space from
			// [s, e] to [s, m-1] and continue your search.
			e = m - 1;
		} else if (t > arr[m]) {
			// to search for 't' go towards the right of the 'm'
			// i.e. reduce search space from [s, e] to [m+1, e]
			s = m + 1;
		} else {
			// t < arr[m]
			// to search for 't' go towards the left of the 'm'
			// i.e. reduce search space from [s, e] to [s, m-1]
			e = m - 1;
		}

	}

	return ans;

}

// time : O(logn)

int f2(int arr[], int n, int t) {

	int s = 0;
	int e = n - 1;

	int ans = -1;

	while (s <= e) {

		int m = s + (e - s) / 2;
		if (arr[m] == t) {
			ans = m;
			// now, look for more occurrences of 't' towards the
			// right of the 'm' i.e. reduce the search space from
			// [s, e] to [m+1, e] and continue your search.
			s = m + 1;
		} else if (t > arr[m]) {
			// to search for 't' go towards the right of the 'm'
			// i.e. reduce search space from [s, e] to [m+1, e]
			s = m + 1;
		} else {
			// t < arr[m]
			// to search for 't' go towards the left of the 'm'
			// i.e. reduce search space from [s, e] to [s, m-1]
			e = m - 1;
		}

	}

	return ans;

}

int main() {

	int arr[] = {10, 20, 30, 30, 30, 30, 30, 40, 40, 40, 50};
	int n = sizeof(arr) / sizeof(int);

	int t = 30;

	int a = f1(arr, n, t);
	if (a == -1) {
		// t is not present
		cout << 0 << endl;
	} else {
		// t is present
		int b = f2(arr, n, t);
		cout << b - a + 1 << endl;
	}

	return 0;
}