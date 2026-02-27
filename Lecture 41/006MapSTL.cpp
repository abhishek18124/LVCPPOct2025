#include<iostream>
#include<map>

using namespace std;

// in a map<> data is by default sorted by keys
// each operation in a map<> takes O(logn) where
// n is the size of the map

int main() {

	map<string, string> capitalMap;

	cout << capitalMap.size() << endl;

	capitalMap["India"] = "Kolkata";
	capitalMap["Russia"] = "Moscow";
	capitalMap["India"] = "New Delhi";
	capitalMap["Israel"] = "Tel Aviv";
	capitalMap["USA"] = "Washington";

	cout << capitalMap.size() << endl;

	cout << capitalMap["India"] << endl;
	cout << capitalMap["USA"] << endl;
	cout << capitalMap["Russia"] << endl;
	cout << capitalMap["Israel"] << endl;

	for (pair<string, string> p : capitalMap) {
		string key = p.first;
		string value = p.second;
		cout << key << " : " << value << endl;
	}

	cout << endl;

	map<string, double> menu;

	menu["tea"] = 15.13;
	menu["coffee"] = 25.72;
	menu["maggi"] = 30.50;

	for (pair<string, double> p : menu) {
		cout << p.first << " : " << p.second << endl;
	}

	return 0;
}