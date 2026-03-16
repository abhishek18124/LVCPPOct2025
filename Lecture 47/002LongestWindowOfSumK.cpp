#include<iostream>

using namespace std;

int main() {

	int arr[] = {2, 3, 2, 4, 0, 2, 0};
	int n = sizeof(arr) / sizeof(int);

	int k = 6;

	int i = 0; // to store the start of the window
	int j = 0; // to store the end of the window

	int wSum = 0; // to store the window sum

	int maxWLenSoFar = 0; // to track the length of the longest
	// window which has a sum equals to k

	// time : O(n)
	// space: O(1)

	while (j < n) {

		// expand the window

		wSum += arr[j];

		// check for the violation of the window property

		if (wSum > k) {

			// window prop. has been violated

			// start shrinking the window till wSum > k

			while (wSum > k) {
				wSum -= arr[i];
				i++;
			}

		}

		// check for the validity of the window, and update the answer

		if (wSum == k) {

			// we've found a valid window

			maxWLenSoFar = max(maxWLenSoFar, j - i + 1);

		}

		// continue expansion of the window

		j++;

	}

	cout << maxWLenSoFar << endl;

	return 0;
}