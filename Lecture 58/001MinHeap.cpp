#include<iostream>
#include<queue>
#include<set>

using namespace std;

int main() {

	priority_queue<int, vector<int>, greater<int>> m;

	m.push(20);
	m.push(10);
	m.push(15);

	while (!m.empty()) {
		cout << m.top() << " ";
		m.pop();
	}

	cout << endl;

	set<int> s;

	s.insert(20);
	s.insert(10);
	s.insert(15); // {10, 15, 20}

	while (!s.empty()) {
		cout << *s.begin() << " ";
		s.erase(s.begin());
	}

	cout << endl;

	set<int> s2;

	s2.insert(10);
	s2.insert(5);
	s2.insert(7);

	for (auto x : s2) {
		cout << x << " ";
	}

	cout << endl;

	s2.erase(7);

	for (auto x : s2) {
		cout << x << " ";
	}

	cout << endl;

	s2.erase(20);

	// when you pass a value to erase() and value doesn't exist in the set<> then nothing happens

	auto it = s2.find(20);

	s2.erase(it);

	for (auto x : s2) {
		cout << x << " ";
	}

	cout << endl;;

	// when you pass an addr of a value to erase() and that value doesn't exist in the set<> then you get an error

	return 0;
}