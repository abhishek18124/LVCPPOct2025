/*

https://codeforces.com/problemset/problem/276/C

e.g.

input
3 3
5 3 2
1 2
2 3
1 3

output
25

input
5 3
5 2 4 1 3
1 5
2 3
2 3

output
33

*/

#include<iostream>
#include<vector>
#include<algorithm>

#define int long long

using namespace std;

int32_t main() {

	int n, q;
	cin >> n >> q;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<int> diff(n + 1, 0);
	while (q--) {
		int l, r;
		cin >> l >> r;
		l--; r--; // since cf is using 1-based indexing and we are using 0-based index thats why we done l--, r-- to transform the question to 0-basd indexing
		diff[l]++;
		diff[r + 1]--;
	}

	for (int i = 1; i <= n; i++) {
		diff[i] += diff[i - 1];
	}

	// for (int i = 0; i <= n; i++) {
	// 	cout << diff[i] << " ";
	// }

	// cout << endl;

	sort(a.begin(), a.end());
	sort(diff.begin(), diff.end() - 1);

	// for (int i = 0; i < n; i++) {
	// 	cout << a[i] << " ";
	// }

	// cout << endl;

	// for (int i = 0; i <= n; i++) {
	// 	cout << diff[i] << " ";
	// }

	// cout << endl;

	int maxsum = 0;
	for (int i = 0; i < n; i++) {
		maxsum += a[i] * diff[i];
	}

	cout << maxsum << endl;

	// time : q.const + n.const + nlogn + nlogn + n.const ~  O(nlogn)
	// space: O(n) due to diff[]

	return 0;
}