#include<iostream>
#include<string>

using namespace std;

int main() {

	string str;
	str = "coding";

	cout << str << endl;

	// auto it = str.begin();
	// cout << *it << endl;

	// it = str.begin() + 1;
	// cout << *it << endl;

	cout << str[0] << " " << str.front() << endl;
	cout << str[1] << endl;
	cout << str[2] << endl;
	cout << str[3] << endl;
	cout << str[4] << endl;
	cout << str[5] << " " << str.back() << endl;

	int n = str.size();

	for (int i = 0; i < n; i++) {
		cout << str[i] << endl;
	}

	cout << endl;

	for (int i = 0; str[i] != '\0'; i++) {
		cout << str[i] << endl;
	}


	for (auto it = str.begin(), end = str.end(); it != end; it++) {
		cout << *it << " ";
	}

	cout << endl;

	for (char ch : str) {
		cout << ch << " ";
	}

	cout << endl;

	string str2 = "coding blocks";

	cout << str2 << endl;

	string str3;

	cout << str3.size() << endl;

	return 0;
}










