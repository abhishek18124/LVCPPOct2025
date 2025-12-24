#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

int main() {

	string s;
	// getline(cin >> ws, s);
	getline(cin, s, '$');
	cout << s << endl;

	return 0;
}