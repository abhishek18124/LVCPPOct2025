#include<iostream>

using namespace std;

int main() {

	int x = 10;

	++x; // x++; // or ++x

	cout << "x = " << x << endl;

	int y = 20;

	--y; // y--; // or --y

	cout << "y = " << y << endl;

	int a = 10;

	cout << a++ << endl;
	cout << a << endl;

	int b = 10;

	cout << ++b << endl;
	cout << b << endl;

	return 0;
}