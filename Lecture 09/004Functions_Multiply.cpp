#include<iostream>

using namespace std;

int multiply(int x, int y) {
	int z = x * y;
	return z;
}

int main() {

	cout << multiply(2, 3) << endl;
	cout << multiply(4, 5) << endl;

	int ans = multiply(6, 7);
	cout << ans << endl;

	cout << multiply(10, 20) + 100 << endl;

	return 0;
}