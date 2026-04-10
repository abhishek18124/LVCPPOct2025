#include<iostream>
#include<queue>
#include<set>

using namespace std;

int main() {

	priority_queue<pair<int, int>,
	               vector<pair<int, int>>,
	               greater<pair<int, int>>> m;

	m.push({3, 2});
	m.push({1, 5});
	m.push({2, 6});

	// when you create a minHeap of pair<> then minHeap prop. is based on the 1st member of the pair<>

	while (!m.empty()) {
		pair<int, int> p = m.top();
		cout << p.first << " " << p.second << endl;
		m.pop();
	}

	cout << endl;

	set<pair<int, int>> s;

	// when you create a set of pair<> then set is sorted based on the 1st member of the pair<>

	s.insert({3, 2});
	s.insert({1, 5});
	s.insert({2, 6});

	while (!s.empty()) {
		pair<int, int> p = *s.begin();
		cout << p.first << " " << p.second << endl;
		// s.erase(s.begin());
		s.erase(p);
	}

	cout << endl;

	return 0;
}