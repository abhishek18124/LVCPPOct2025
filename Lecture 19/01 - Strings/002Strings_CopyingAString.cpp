#include<iostream>
#include<string>

using namespace std;

int main() {

	int x = 10;
	int y = x;

	int z;
	z = x;

	string s1 = "coding";
	string s2 = s1; // copy constructor

	string s3;
	s3 = s1; // copy assignment operator

	string s4(s1); // copy constructor

	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;

	s2[0] = 'z';
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;

	s3[1] = 'p';
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;

	s4[2] = 'x';
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;


	return 0;
}