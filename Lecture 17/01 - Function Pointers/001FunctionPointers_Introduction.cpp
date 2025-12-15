#include<iostream>

using namespace std;

void greet() {
	cout << "namaste" << endl;
}

int add(int a, int b) {
	return a + b;
}

bool ascending(int a, int b) {
	return a > b; // return true if a > b otherwise return false
}

int main() {

	cout << (void*)&greet << endl;
	cout << (void*)&add << endl;
	cout << (void*)&ascending << endl << endl;

	// using '&' to extract addresses of functions is optional

	cout << (void*)greet << endl;
	cout << (void*)add << endl;
	cout << (void*)ascending << endl << endl;

	void (*gptr)() = &greet;
	int (*aptr)(int, int) = &add;
	bool (*ascptr)(int, int) = &ascending;

	cout << (void*)gptr << endl;
	cout << (void*)aptr << endl;
	cout << (void*)ascptr << endl << endl;

	(*gptr)();
	cout << (*aptr)(5, 10) << endl;
	cout << (*ascptr)(5, 10) << endl << endl;

	// using * to call function via function ptr is optional

	gptr();
	cout << aptr(5, 10) << endl;
	cout << ascptr(5, 10) << endl << endl;

	greet();
	cout << add(5, 10) << endl;
	cout << ascending(5, 10) << endl << endl;

	(*greet)();
	cout << (*add)(5, 10) << endl;
	cout << (*ascending)(5, 10) << endl << endl;

	return 0;
}








