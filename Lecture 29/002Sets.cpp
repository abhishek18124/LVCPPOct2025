/*

	https://cplusplus.com/reference/set/set/?kw=set
	https://cplusplus.com/reference/set/multiset/?kw=multiset

	> insert/erase/find is logarithmic i.e. O(logn)
	> values are inserted in the sorted order
	> set contains only distinct values
	> multiset allows duplicate values

*/

#include<iostream>
#include<set>

using namespace std;

int main() {

	set<int> s; // s is a set of integers
	// set<int, greater<int>> s; // s is a set of integers

	// use greater<int> if you want set<> to be maintained in dec. order

	cout << s.size() << endl;

	s.empty() ? cout << "set<> is empty" << endl :
	                 cout << "set<> is non-empty" << endl;

	s.insert(3);

	cout << s.size() << endl;

	s.empty() ? cout << "set<> is empty" << endl :
	                 cout << "set<> is non-empty" << endl;

	s.insert(2);
	s.insert(4);

	cout << s.size() << endl;

	s.empty() ? cout << "set<> is empty" << endl :
	                 cout << "set<> is non-empty" << endl;

	for (int x : s) {
		cout << x << " ";
	}

	cout << endl;

	for (const int& x : s) {
		cout << x << " ";
	}

	cout << endl;

	// for (int i = 0; i < s.size(); i++) {
	// 	cout << s[i] << " ";
	// }

	for (auto it = s.begin(), end = s.end(); it != end; it++) {
		cout << *it << " ";
	}

	cout << endl;

	s.erase(3);

	cout << s.size() << endl;

	for (int x : s) {
		cout << x << " ";
	}

	cout << endl;

	s.erase(10); // since 10 is not present nothing will happen

	s.insert(1);
	s.insert(5);

	for (int x : s) {
		cout << x << " ";
	}

	cout << endl;

	s.insert(1); // since 1 is already present, nothing will happen

	for (int x : s) {
		cout << x << " ";
	}

	cout << endl;

	s.erase(s.begin());

	for (int x : s) {
		cout << x << " ";
	}

	cout << endl;

	auto it = s.begin();

	it++;

	s.erase(it);

	for (int x : s) {
		cout << x << " ";
	}

	cout << endl;

	// if you pass an invalid iterator / addr
	// to s.erase(...) it will lead to an error

	s.insert(6);
	s.insert(4);
	s.insert(8);

	for (int x : s) {
		cout << x << " ";
	}

	cout << endl;

	int key = 5;

	if (s.count(key)) {
		cout << key << " is present in the set<>" << endl;
	} else {
		cout << key << " is not present in the set<>" << endl;
	}

	key = 10;

	if (s.count(key)) {
		cout << key << " is present in the set<>" << endl;
	} else {
		cout << key << " is not present in the set<>" << endl;
	}

	key = 6;

	if (s.find(key) != s.end()) {
		cout << key << " is present" << endl;
	} else {
		cout << key << " is not present" << endl;
	}

	key = 16;

	if (s.find(key) != s.end()) {
		cout << key << " is present" << endl;
	} else {
		cout << key << " is not present" << endl;
	}

	s.erase(s.find(5));

	for (int x : s) {
		cout << x << " ";
	}

	cout << endl;

	s.clear();

	cout << s.size() << endl;

	s.empty() ? cout << "set<> is empty" << endl :
	                 cout << "set<> is non-empty" << endl;


	return 0;
}