#include<iostream>

using namespace std;

int main() {

	int x = 10;
	int* ptr1 = &x; // ptr to int
	const int* ptr2 = &x; // ptr to const-int
	int* const ptr3 = &x; // const ptr to int
	const int* const ptr4 = &x; // const ptr to const-int

	int const * ptr5 = &x; // ptr5 is a pointer to a const-int
	cout << *ptr5 << endl;
	// (*ptr5)++;

	int y = 20;
	ptr5 = &y;

	return 0;
}