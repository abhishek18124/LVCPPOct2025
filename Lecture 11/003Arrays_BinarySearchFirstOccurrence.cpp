#include<iostream>

using namespace std;

// time : O(logn)

int f(int arr[], int n, int t) {

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

int main() {

	int arr[] = {10, 10, 20, 30, 30, 30, 30, 40, 40, 40, 50};
	int n = sizeof(arr) / sizeof(int);

	int t = 40;

	cout << f(arr, n, t) << endl;

	return 0;
}