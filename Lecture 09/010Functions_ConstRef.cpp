#include<iostream>

using namespace std;

int main() {

	int x = 10;
	int&y = x;
	const int&z = x;

	cout << x << " " << y << " " << z << endl;

	x++;

	cout << x << " " << y << " " << z << endl;

	y++;

	cout << x << " " << y << " " << z << endl;

	// z++; // error since z is a const-ref

	cout << x << " " << y << " " << z << endl;

	const int a = 10;

	// int&b = a; // error since a is a const var, it ref must be const

	return 0;
}