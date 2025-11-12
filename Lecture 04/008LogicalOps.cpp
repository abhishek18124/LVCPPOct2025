#include<iostream>

using namespace std;

int main() {

	cout << "true && true = " << (true && true) << endl; // 1
	cout << "true && false = " << (true && false) << endl; // 0
	cout << "false && true = " << (false and true) << endl; // 0
	cout << "false && false = " << (false and false) << endl; // 0

	cout << endl;

	cout << "true || true = " << (true || true) << endl; // 1
	cout << "true || false = " << (true || false) << endl; // 1
	cout << "false or true = " << (false or true) << endl; // 1
	cout << "false or false = " << (false or false) << endl;  // 0

	cout << endl;

	cout << "!true = " << (!true) << endl; // 0
	cout << "!false = " << (!false) << endl; // 1

	return 0;
}