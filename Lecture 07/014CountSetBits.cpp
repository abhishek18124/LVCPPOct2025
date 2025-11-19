#include<iostream>

using namespace std;

int main() {

	int n = 61;

	cout << __builtin_popcount(n) << endl;
	cout << __builtin_popcountll(n) << endl;

	int cnt = 0; // to track the no. of set bits in 'n'

	for (int k = 0; k < 32; k++) {
		// check if the kth bit of n is set or not
		if ((n >> k) & 1) {
			// kth bit of n is set
			cnt++;
		}
	}

	cout << cnt << endl;


	return 0;
}