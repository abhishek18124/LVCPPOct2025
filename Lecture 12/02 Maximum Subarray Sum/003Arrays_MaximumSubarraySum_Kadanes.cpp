#include<iostream>
#include<vector>

using namespace std;

// time : O(n)
// space: O(n) due x[]

int maximumSubarraySumUsingKadanes(const vector<int>& arr) {

	int n = arr.size();

	vector<int> x(n);
	x[0] = arr[0];

	int maxSoFar = x[0];

	for (int i = 1; i <= n - 1; i++) {
		x[i] = max(x[i - 1] + arr[i], arr[i]);
		maxSoFar = max(maxSoFar, x[i]);
	}

	return maxSoFar;

}

// time : O(n)
// space: O(1)

int maximumSubarraySumUsingKadanesSpaceOptimised(const vector<int>& arr) {

	int n = arr.size();

	int x;
	x = arr[0]; // init x stores x[0]

	int maxSoFar = x;

	for (int i = 1; i <= n - 1; i++) {
		x = max(x + arr[i], arr[i]);
		maxSoFar = max(maxSoFar, x);
	}

	return maxSoFar;

}

int main() {

	vector<int> arr = { -3, 2, -1, 4, -5};

	cout << maximumSubarraySumUsingKadanes(arr) << endl;
	cout << maximumSubarraySumUsingKadanesSpaceOptimised(arr) << endl;

	return 0;

}