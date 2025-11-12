#include<iostream>

using namespace std;

int main() {

	/*

	A -> v.good
	B -> good
	C -> avg.
	D -> bad
	E -> v.bad
	F -> fail

	*/

	char grade;
	cin >> grade;

	// if (grade == 'A') {
	// 	cout << "v.good" << endl;
	// } else if (grade == 'B') {
	// 	cout << "good" << endl;
	// } else if (grade == 'C') {
	// 	cout << "avg." << endl;
	// } else if (grade == 'D') {
	// 	cout << "bad" << endl;
	// } else if (grade == 'E') {
	// 	cout << "v.bad" << endl;
	// } else if (grade == 'F') {
	// 	cout << "fail" << endl;
	// } else {
	// 	cout << "invalid grade" << endl;
	// }

	switch (grade) { // char / int can switched
	case 'A': cout << "v.good" << endl; break;
	case 'B': cout << "good" << endl; break;
	case 'C': cout << "avg." << endl; break;
	case 'D': cout << "bad" << endl; break;
	case 'E': cout << "v.bad" << endl; break;
	case 'F': cout << "fail" << endl; break;
	default: cout << "invalid grade" << endl; break;
	}


	return 0;
}