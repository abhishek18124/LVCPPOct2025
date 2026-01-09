/*

https://www.spoj.com/problems/AGGRCOW/

*/

#include<iostream>
#include<climits>
#include<vector>

using namespace std;

bool f(int n, int c, vector<int>& pos, int m) { // linear

	// can I place c cows in n stalls s.t. the distance b/w any two of them is >= m

	// place the 1st cow in the 1st stall

	int prevCowPos = pos[0];
	c--;

	// try to place the remaining cows

	for (int i = 1; i < n; i++) {

		// can I place the next cow in the ith stall

		if (pos[i] - prevCowPos >= m) {

			// place the next cow in the ith stall

			prevCowPos = pos[i];
			c--;

			if (c == 0) {
				// you've managed to place c cows in n stalls at a min. dist. of >= m
				return true;
			}

		}

	}

	// you were not able to place c cows in n stalls
	// at a min. dist of >= m
	return false;

}

int main() {

	int t;
	cin >> t;

	while (t--) {

		int n, c;
		cin >> n >> c;

		vector<int> pos(n);
		for (int i = 0; i < n; i++) {
			cin >> pos[i];
		}

		sort(pos.begin(), pos.end()); // nlogn

		int s = INT_MAX;
		for (int i = 1; i < n; i++) {
			s = min(pos[i] - pos[i - 1], s);
		}

		int e = pos[n - 1] - pos[0];

		int ans;

		while (s <= e) { // log(e-s) * n // 30.n

			int m = s + (e - s) / 2;

			// can I place c cows in n stalls s.t. the distance b/w any two of them is >= m

			if (f(n, c, pos, m)) {

				// yes, you can place c cows in n stalls s.t. the dist. b/w any two of them is >= m
				ans = m;
				s = m + 1;

			} else {

				// you cannot place c cows in n stalls s.t. the dist. b/w any two of them is >= m
				e = m - 1;

			}

		}

		cout << ans << endl;

		// total time : nlogn + 30n ~ O(nlogn)

	}

	return 0;

}