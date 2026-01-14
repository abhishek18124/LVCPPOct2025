#include<iostream>

using namespace std;

int f(int x, int y) {

	// base case

	if (y == 0) {
		// f(x, 0) = find the product of x and 0
		return 0;
	}

	// recursive case

	// f(x, y) : find the product of x and y

	// 1. ask your friend to find the product of x and y - 1

	int A = f(x, y - 1);

	// 2. use the answer given by friend to build the solution
	// for the given problem

	return x + A;

}

int main() {

	int x = 3;
	int y = 4;

	cout << f(x, y) << endl;

	return 0;
}