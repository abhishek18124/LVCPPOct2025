#include<iostream>

using namespace std;

int multiply(int x, int y) {
	int z = x * y;
	return z;
}

int main() {

	int x = 3;
	int y = 4;

	cout << multiply(x, y) << endl;

	return 0;
}