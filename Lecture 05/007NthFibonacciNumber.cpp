#include<iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	// if(n == 0) {
	// 	cout << 0 << endl;
	// } else if(n == 1) {
	// 	cout << 1 << endl;
	// } else {
	// 	// n >= 2
	// 	...
	// }

	// time : O(n)

	if (n == 0 || n == 1) {
		cout << n << endl;
	} else {
		// n >= 2
		int a = 0; // 0th fib. no.
		int b = 1; // 1st fib. no.

		int i = 1;
		while (i <= n - 1) {
			int c = a + b;
			a = b;
			b = c;
			i = i + 1;
		}
		cout << b << endl;
	}

	return 0;
}