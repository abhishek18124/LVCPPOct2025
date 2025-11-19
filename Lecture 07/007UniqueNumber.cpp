#include<iostream>
#include<climits>

using namespace std;

int main() {

	int n;
	cin >> n;

	// time : O(n)
	// space: O(1)

	int ans = 0; // to store the unique number

	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		ans = ans ^ x; // ans ^= x;
	}

	cout << ans << endl;

	return 0;
}