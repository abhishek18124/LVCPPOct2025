#include<iostream>
#include<string>

using namespace std;

int main() {

	string s = "abc";
	s.push_back('d');
	cout << s << endl;
	s.pop_back();
	cout << s << endl;

	string t = "def";

	cout << s + t << endl;
	cout << t + s << endl;

	s = s + t;

	cout << s << endl;

	return 0;
}