#include<iostream>

using namespace std;

void incr(int y) { // here x is passed by value so changes done to y (param) won't be reflected in x(arg)
	y++;
}

int main() {

	int x = 0;

	cout << "x = " << x << endl;

	incr(x);

	cout << "x = " << x << endl;

	return 0;
}