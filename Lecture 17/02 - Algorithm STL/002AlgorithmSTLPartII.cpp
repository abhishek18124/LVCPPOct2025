#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

// return true if you want a to be ordered before
// b otherwise return false

bool lengthCmp(string a, string b) {

	if (a.size() < b.size()) {

		// since a.size() is < b.size() and we are sorting in inc. order
		// based on length so we want a to be ordered before b hence we are
		// returning true

		return true;
	} else {
		return false;
	}

}

int main() {

	vector<int> v = {10, 40, 30, 20, 50};

	// sorting v[] in decreasing order

	// sort(v.begin(), v.end());
	// reverse(v.begin(), v.end());

	// sort(v.rbegin(), v.rend());

	sort(v.begin(), v.end(), greater<int>());

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	cout << endl;


	int arr[] = {20, 30, 50, 10, 40};
	int n = sizeof(arr) / sizeof(int);

	// sorting a sequence in the decreasing order

	// using greater<T>() function object / functor

	sort(arr, arr + n, greater<int>());

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	// using a customer comparator

	vector<string> names = {"rimmi", "shubhra", "yash", "himanshi", "keshav"};

	for (int i = 0; i < names.size(); i++) {
		cout << names[i] << " ";
	}

	cout << endl;

	sort(names.begin(), names.end()); // sorts vector<> in lexicographicall increasing order

	for (int i = 0; i < names.size(); i++) {
		cout << names[i] << " ";
	}

	cout << endl;

	// sort(names.rbegin(), names.rend()); // sorts vector<> in lexicographicall decreasing order
	sort(names.begin(), names.end(), greater<string>()); // sorts vector<> in lexicographicall decreasing order

	for (int i = 0; i < names.size(); i++) {
		cout << names[i] << " ";
	}

	cout << endl;

	// sort(names.begin(), names.end(), &lengthCmp);
	sort(names.begin(), names.end(), lengthCmp);

	for (int i = 0; i < names.size(); i++) {
		cout << names[i] << " ";
	}

	cout << endl;

	return 0;
}
