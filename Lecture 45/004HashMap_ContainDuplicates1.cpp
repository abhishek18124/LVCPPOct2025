#include<iostream>
#include<vector>
#include<map>
#include<set>

using namespace std;

// time : O(nlogn)
// space: O(n)

bool isDuplicatePresent(const vector<int>& v) {

	map<int, int> freqMap;
	for (int num : v) {
		freqMap[num]++;
		if (freqMap[num] > 1) {
			// duplicate found
			return true;
		}
	}

	// for (pair<int, int> p : freqMap) {
	// 	int num = p.first;
	// 	int freq = p.second;
	// 	cout << num << " : " << freq << endl;
	// }

	// cout << endl;

	// for (auto [num, freq] : freqMap) {
	// 	cout << num << " : " << freq << endl;
	// }

	// cout << endl;

	return false; // no duplicate found

}

// time : O(nlogn)
// space : O(n)

bool isDuplicatePresentUsingSet(const vector<int>& v) {

	set<int> s;

	for (int num : v) {
		if (s.find(num) == s.end()) {
			// num is not present in set<>
			s.insert(num);
		} else {
			// num is already present in set<>, duplicate found
			return true;
		}
	}

	// no duplicates

	return false;

}

int main() {

	vector<int> v = {10, 20, 30, 40, 10};

	isDuplicatePresent(v) ? cout << "duplicate found" << endl :
	                             cout << "no duplicates found" << endl;

	isDuplicatePresentUsingSet(v) ? cout << "duplicate found" << endl :
	                                     cout << "no duplicates found" << endl;

	return 0;
}
