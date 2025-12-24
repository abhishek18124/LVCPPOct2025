#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main() {

	string s = "xuabz";

	sort(s.begin(), s.end()); // string is sorted in inc. order

	cout << s << endl;

	// sort(s.rbegin(), s.rend()); // string is sorted in dec. order
	sort(s.begin(), s.end(), greater<char>()); // string is sorted in dec. order

	cout << s << endl;

	return 0;
}