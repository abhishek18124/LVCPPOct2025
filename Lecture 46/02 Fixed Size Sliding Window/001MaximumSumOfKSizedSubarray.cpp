#include<iostream>

using namespace std;

int main() {

	int arr[] = {1, 4, 2, 7, 6, 3, 5};
	int n = sizeof(arr) / sizeof(int);
	int k = 4;

	int i = 0; // to store the start of the window

	int j = 0; // to store the end of the window

	int wSum = 0; // to store the window sum
	int maxWSumSoFar;   // to track the maximum window sum

	// time  : O(n)
	// space : O(1)

	// compute the sum of 1st window

	while (j < k) {
		wSum += arr[j];
		j++;
	}

	maxWSumSoFar = wSum;

	// compute the sum for the remaining windows

	while (j < n) {

		// slide the window

		wSum -= arr[i];
		i++;
		wSum += arr[j];

		// update the ans

		maxWSumSoFar = max(maxWSumSoFar, wSum);

		j++;

	}

	cout << maxWSumSoFar << endl;

	return 0;
}

