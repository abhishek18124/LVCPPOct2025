/*
		https://cplusplus.com/reference/utility/pair/?kw=pair

		This 'pair' class couples together a pair of values, which maybe of different
		types (T1 and T2).The individual values of a pair can be accessed through its
		public members 'first' and 'second'.
*/

#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>

using namespace std;

int main() {

	pair<string, int> p1;

	p1.first = "rimmi";
	p1.second = 20;

	cout << p1.first << " " << p1.second << endl;

	pair<string, string> p2;

	p2.first = "india";
	p2.second = "new delhi";

	cout << p2.first << " " << p2.second << endl;

	pair<int, string> p3;

	cin >> p3.first;
	cin >> p3.second;

	cout << p3.first << " " << p3.second << endl;

	pair<int, pair<string, int>> p4;

	cin >> p4.first >> p4.second.first >> p4.second.second;

	cout << p4.first << " " << p4.second.first << " " << p4.second.second << endl;

	vector<pair<int, string>> v;

	v.push_back({11, "Feb"});
	v.push_back({3, "Dec"});
	v.push_back({4, "Apr"});
	v.push_back({3, "Aug"});

	for (pair<int, string> p : v) {
		cout << p.first << " " << p.second << endl;
	}

	cout << endl;

	// by default a vector<> of pair<> is sorted in inc. order
	// based on the 1st member of the pair<> unless the first
	// member match in which case 2nd member is used to decide
	// the output ordering

	sort(v.begin(), v.end());

	for (pair<int, string> p : v) {
		cout << p.first << " " << p.second << endl;
	}

	return 0;
}