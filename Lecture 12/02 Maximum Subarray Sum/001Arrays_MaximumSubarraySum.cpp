#include<iostream>
#include<vector>
#include<climits>

using namespace std;

// time : O(n^3)
// space: O(1)

int maximumSubarraySum(const vector<int>& arr) {

	int n = arr.size();
	int maxSoFar = INT_MIN; // to track the maximum subarray sum

	for (int i = 0; i <= n - 1; i++) {
		for (int j = i; j <= n - 1; j++) {
			// find the sum of the subarray that starts at the ith index
			// and ends at the jth index

			int sum = 0; // to track the sum of the subarray that starts at the ith index and ends at the jth index

			for (int k = i; k <= j; k++) {
				sum += arr[k];
			}

			// if(sum > maxSoFar) {
			// 	maxSoFar = sum;
			// }

			maxSoFar = max(maxSoFar, sum);

		}

	}

	return maxSoFar;

}

int main() {

	vector<int> arr = { -2, 1, -3, 4, -1, 2, 1, -5, 4};

	cout << maximumSubarraySum(arr) << endl;

	return 0;
}