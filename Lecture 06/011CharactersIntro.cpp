#include<iostream>

using namespace std;

int main() {

	char ch;

	ch = 'A';

	cout << ch << endl;

	cout << (int)ch << endl;

	cin >> ch;

	cout << ch << endl;

	cout << (int)ch << endl;

	ch = 'a';

	cout << ch << endl;

	cout << (int)ch << endl;

	ch = 'z';

	cout << ch << endl;

	cout << (int)ch << endl;

	ch = '0';

	cout << ch << endl;

	cout << (int)ch << endl;

	ch = '9';

	cout << ch << endl;

	cout << (int)ch << endl;

	ch = '1';

	cout << (int)ch << endl;

	cout << ch - '0' << endl;

	int x = ch - '0';

	cout << x << endl;

	ch = 'z';

	int y = ch; // implicit type-casting

	cout << y << endl;

	return 0;
}