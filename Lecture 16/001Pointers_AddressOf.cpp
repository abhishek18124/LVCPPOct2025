#include<iostream>

using namespace std;

int main() {

	int x = 10;
	cout << "x = " << x << endl;
	cout << "sizeof(x) = " << sizeof(x) << "B" << endl;
	cout << "&x = " << &x << endl; // 0x....
	cout << "sizeof(&x) = " << sizeof(&x) << "B" << endl;

	cout << endl;

	double y = 3.14;
	cout << "y = " << y << endl;
	cout << "sizeof(y) = " << sizeof(y) << "B" << endl;
	cout << "&y = " << &y << endl; // 0x....
	cout << "sizeof(&y) = " << sizeof(&y) << "B" << endl;

	cout << endl;

	bool b = true;
	cout << "b = " << b << endl;
	cout << "sizeof(b) = " << sizeof(b) << "B" << endl;
	cout << "&b = " << &b << endl; // 0x....
	cout << "sizeof(&b) = " << sizeof(&b) << "B" << endl;

	cout << endl;

	char ch = 'A';
	cout << "ch = " << ch << endl;
	cout << "sizeof(ch) = " << sizeof(ch) << "B" << endl;
	cout << "&ch = " << &ch << endl; // 0x....
	cout << "sizeof(&ch) = " << sizeof(&ch) << "B" << endl;

	cout << endl;

	return 0;

}