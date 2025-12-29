#include<iostream>

using namespace std;

int main() {

	int arr[3][4];

	cout << "sizeof(arr) = " << sizeof(arr) << "B" << endl;

	char brr[10][20];

	cout << "sizeof(brr) = " << sizeof(brr) << "B" << endl;

	double crr[6][7];

	cout << "sizeof(crr) = " << sizeof(crr) << "B" << endl;

	return 0;
}