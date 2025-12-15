#include<iostream>
#include<algorithm>

using namespace std;

int main() {

	int arr[] = {50, 40, 10, 10, 10, 20, 30};
	int n = sizeof(arr) / sizeof(int);

	int key = 20;

	// 1. searching for a key in a sequence using find()

	auto addr = find(arr, arr + n, key);
	cout << addr << endl;
	cout << &arr[4] << endl;
	cout <<  addr - arr << endl;

	key = 100;

	auto addr1 = find(arr, arr + n, key);
	if (addr1 == arr + n) {
		cout << key << " is not present" << endl;
	}

	// 2. counting the occurrences of a key in a sequence using count()

	key = 100;

	cout << count(arr, arr + n, key) << endl;


	return 0;
}
