#include<iostream>

using namespace std;

int f(int x, int y) {

	// base case

	if (y == 0) {
		// f(x, 0) = find pow(x, 0)
		return 1;
	}

	// recursive case

	// f(x, y) = find pow(x, y)

	// 1. ask your friend to find pow(x, y/2)

	int A = f(x, y / 2);

	// 2. use the answer from your friend to find
	// the solution for the given problem

	if (y % 2 == 0) {
		return A * A;
	} else {
		return A * A * x;
	}

}

int main() {

	int x = 12;
	int y = 2;

	cout << f(x, y) << endl;

	return 0;
}