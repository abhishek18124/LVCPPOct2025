/*

e.g.

input
5 3
4 1 5 2 3
0 2 5
2 3 2
3 4 7

output
9 6 12 11 10

*/

#include<iostream>
#include<vector>

using namespace std;

int main() {

	int n, q;
	cin >> n >> q;

	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	vector<int> diff(n + 1);
	while (q--) {
		int l, r, x;
		cin >> l >> r >> x;
		diff[l] += x;
		diff[r + 1] -= x;
	}

	// for (int i = 0; i <= n; i++) {
	// 	cout << diff[i] << " ";
	// }

	// cout << endl;

	for (int i = 1; i <= n; i++) {
		diff[i] += diff[i - 1];
	}

	// for (int i = 0; i <= n; i++) {
	// 	cout << diff[i] << " ";
	// }

	// cout << endl;

	for (int i = 0; i < n; i++) {
		arr[i] += diff[i];
	}

	// time : q.const + n.const + n.const ~ O(q+n)
	// space: n+1 due to diff[] ~ O(n)

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;

}