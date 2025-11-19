#include<iostream>

using namespace std;

int main() {

	int n = 61;
	int cnt = 0; // to count no. of set bits in n

	while (n > 0) { // n has >= 1 set bits

		// clear the rightmost set bit of n

		n = n & (n - 1);

		cnt++;

	}

	cout << cnt << endl;

	return 0;
}
