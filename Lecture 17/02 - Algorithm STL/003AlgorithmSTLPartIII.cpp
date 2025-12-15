#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {


	vector<int> v = {500, 400, 100, 200, 300};

	int arr[] = {20, 40, 10, 50, 30};
	int n = sizeof(arr) / sizeof(int);

	// 1. finding the minimum value in a sequence

	cout << *min_element(v.begin(), v.end()) << endl;
	cout << *min_element(arr, arr + n) << endl;

	cout << min_element(arr, arr + n) - arr << endl;

	// 2. finding the maximum value in a sequence

	cout << *max_element(v.begin(), v.end()) << endl;
	cout << *max_element(arr, arr + n) << endl;

	cout << max_element(arr, arr + n) - arr << endl;

	return 0;
}
