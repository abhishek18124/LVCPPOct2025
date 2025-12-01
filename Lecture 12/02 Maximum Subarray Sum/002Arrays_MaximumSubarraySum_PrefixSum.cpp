#include<iostream>
#include<vector>
#include<climits>

using namespace std;

// time : n.const + n^2.const ~ O(n^2)
// space: O(n) due to psum[]

int maximumSubarraySum(const vector<int>& arr) {

	int n = arr.size();

	vector<int> psum(n);
	psum[0] = arr[0];
	for (int i = 1; i <= n - 1; i++) {
		psum[i] = psum[i - 1] + arr[i];
	}

	int maxSoFar = INT_MIN; // to track the maximum subarray sum

	for (int i = 0; i <= n - 1; i++) {
		for (int j = i; j <= n - 1; j++) {
			// find the sum of the subarray that starts at the ith index
			// and ends at the jth index
			int sum = i == 0 ? psum[j] : psum[j] - psum[i - 1];
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