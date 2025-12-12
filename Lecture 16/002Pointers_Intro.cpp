#include<iostream>

using namespace std;

int main() {

	int x = 10;

	int* xptr; // pointer declaration
	xptr = &x; // pointer assignment

	cout << "x = " << x << endl;
	cout << "sizeof(x) = " << sizeof(x) << endl;
	cout << "&x = " << &x << endl;
	cout << "sizeof(&x) = " << sizeof(&x) << "B" << endl;
	cout << "xptr = " << xptr << endl;
	cout << "sizeof(xptr) = " << sizeof(xptr) << "B" << endl;

	cout << endl;

	double y = 3.14;
	double* yptr = &y;

	cout << "y = " << y << endl;
	cout << "sizeof(y) = " << sizeof(y) << "B" << endl;
	cout << "&y = " << &y << endl; // 0x....
	cout << "sizeof(&y) = " << sizeof(&y) << "B" << endl;
	cout << "yptr = " << yptr << endl;
	cout << "sizeof(yptr) = " << sizeof(yptr) << "B" << endl;

	cout << endl;

	bool b = true;
	bool* bptr = &b;

	cout << "b = " << b << endl;
	cout << "sizeof(b) = " << sizeof(b) << "B" << endl;
	cout << "&b = " << &b << endl; // 0x....
	cout << "sizeof(&b) = " << sizeof(&b) << "B" << endl;
	cout << "bptr = " << bptr << endl;
	cout << "sizeof(bptr) = " << sizeof(bptr) << "B" << endl;

	cout << endl;

	char ch = 'A';
	char* chptr = &ch;

	cout << "ch = " << ch << endl;
	cout << "sizeof(ch) = " << sizeof(ch) << "B" << endl;
	cout << "&ch = " << &ch << endl; // 0x....
	cout << "sizeof(&ch) = " << sizeof(&ch) << "B" << endl;
	cout << "chptr = " << chptr << endl;
	cout << "sizeof(chptr) = " << sizeof(chptr) << "B" << endl;

	cout << endl;

	return 0;
}