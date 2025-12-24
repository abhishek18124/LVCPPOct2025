#include<iostream>
#include<string>

using namespace std;

int main() {

	string str = "ababbaab";
	int n = str.size();

	int ans = 0; // to track rudeness

	int cntb = 0;

	// time : O(n)
	// space: O(1)

	for (int i = n - 1; i >= 0; i--) {

		char ch = str[i];
		if (ch == 'a') {
			ans += cntb;
		} else if (ch == 'b') {
			cntb++;
		}

	}

	cout << ans << endl;

	return 0;
}