#include<iostream>
#include<climits>

using namespace std;

int main() {

	int n;
	cin >> n;

	int maxSoFar = INT_MIN; // to track the "maximum or largest" element seen so far
	int minSoFar = INT_MAX; // to track the "minimum or smallest" element seen so far

	int i = 1;

	while (i <= n) {

		int x;
		cin >> x;

		if (x > maxSoFar) {
			maxSoFar = x;
		}

		if (x < minSoFar) {
			minSoFar = x;
		}

		i = i + 1;

	}

	cout << maxSoFar << endl;
	cout << minSoFar << endl;

	return 0;
}