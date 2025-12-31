/*

e.g.

input

5 5 3

2 3 0 1 5
4 7 9 3 2
6 8 1 0 4
9 5 4 2 3
0 6 8 6 1

0 0 1 1
1 2 3 4
2 0 4 1

output

16
28
34

*/

#include<iostream>
#include<vector>

using namespace std;

int main() {

	int m, n, q;
	cin >> m >> n >> q;

	vector<vector<int>> v(m, vector<int>(n));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> v[i][j];
		}
	}

	vector<vector<int>> psum(m, vector<int>(n)); // mn.const
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			psum[i][j] = v[i][j];
			if (i > 0) psum[i][j] += psum[i - 1][j]; // red box
			if (j > 0) psum[i][j] += psum[i][j - 1]; // green box
			if (i > 0 and j > 0) psum[i][j] -= psum[i - 1][j - 1]; // blue box
		}
	}

	// for (int i = 0; i < m; i++) {
	// 	for (int j = 0; j < n; j++) {
	// 		cout << psum[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	// cout << endl;

	while (q--) { // q.const
		int l1, r1, l2, r2;
		cin >> l1 >> r1 >> l2 >> r2;
		int ans = psum[l2][r2];
		if (l1 > 0) ans -= psum[l1 - 1][r2];
		if (r1 > 0) ans -= psum[l2][r1 - 1];
		if (l1 > 0 and r1 > 0) ans += psum[l1 - 1][r1 - 1];
		cout << ans << endl;
	}

	// time : mn.const + q.const ~ O(mn + q)
	// space: mn due to psum[][] ~ O(mn)

	return 0;
}