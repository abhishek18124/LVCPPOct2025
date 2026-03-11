/*

	Implement a phonebook storing mapping between person's name and
	their phone numbers using an unordered_map.

*/

#include<iostream>
#include<map>
#include<vector>

using namespace std;

int main() {

	map<string, vector<string>> phoneMap;

	cout << phoneMap.size() << endl;

	phoneMap["Tushar"].push_back("1234");
	phoneMap["Tushar"].push_back("5678");
	phoneMap["Tushar"].push_back("0000");

	phoneMap["Rimmi"].push_back("1111");
	phoneMap["Rimmi"].push_back("2222");

	phoneMap["Abhishek"].push_back("9999");

	for (pair<string, vector<string>> p : phoneMap) {
		string contactName = p.first;
		vector<string> phoneNums = p.second;
		cout << contactName << " : ";
		for (string num : phoneNums) {
			cout << num << " ";
		}
		cout << endl;
	}

	cout << endl;

	for (auto [contactName, phoneNums] : phoneMap) {
		cout << contactName << " : ";
		for (string num : phoneNums) {
			cout << num << " ";
		}
		cout << endl;
	}

	// cout << phoneMap["Tushar"].size() << endl;

	return 0;
}