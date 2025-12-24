#include<iostream>
#include<string>

using namespace std;

int main() {

	string s = "abcdabcd";
	string t = "cd";

	cout << s.find(t) << endl;
	cout << s.rfind(t) << endl;

	string w = "zzz";

	cout << s.find(w) << endl;
	cout << string::npos << endl;
	cout << (string::npos == -1) << endl;

	return 0;
}