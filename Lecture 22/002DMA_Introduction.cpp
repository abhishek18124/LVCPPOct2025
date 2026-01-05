#include<iostream>

using namespace std;

int main() {

	// type* ptr = new type

	int* ptr = new int;

	*ptr = 20;

	cout << *ptr << endl;

	char* chptr = new char;

	*chptr = 'A';

	cout << *chptr << endl;

	double* dptr = new double;

	*dptr = 3.14;

	cout << *dptr << endl;

	string* sptr = new string;

	*sptr = "hi";

	cout << *sptr << endl;

	return 0;
}