// 1 <= n <= 100

#include<iostream>

using namespace std;

int main() {

	int arr[100];

	// int n;
	// cin >> n;

	// int t;
	// cin >> t;

	int n, t;
	cin >> n >> t;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	// time : n.const ~ O(n)

	int i;

	int cntr = 0; // to track no. of occurrences of 't' in the arr[]

	for (i = 0; i < n; i++) {

		if (arr[i] == t) {

			// you've found the 1st occurrence
			// of the 't' at index i

			cout << i << endl;
			cntr++;

		}

	}

	if (cntr == 0) {
		// no occurrences of 't' was found in the arr[]
		cout << -1 << endl;
	}

	return 0;
}