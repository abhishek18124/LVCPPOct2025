#include<iostream>

using namespace std;

int main() {

	int n = 42;
	int cnt = 0; // to track the no. of set bits in 'n'

	while (n > 0) {

		int rightmostBit = n & 1; // 0th bit of n
		if (rightmostBit == 1) {
			// rightmostBit is set
			cnt++;
		}

		n = n >> 1;

	}


	cout << cnt << endl;

	n = 42;
	cnt = 0;

	while (n > 0) {

		if (n % 2 == 1) {
			// n is odd therefore rightmost bit is set
			cnt++;
		}

		n = n / 2;

	}

	cout << cnt << endl;


	return 0;
}