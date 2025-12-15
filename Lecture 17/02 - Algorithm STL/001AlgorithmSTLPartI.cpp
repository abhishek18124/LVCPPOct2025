#include<iostream>
#include<algorithm>

using namespace std;

int main() {

	int arr[] = {20, 10, 50, 30, 40};
	int n = sizeof(arr) / sizeof(int);

	// 1. sorting a sequence using built-in sort() in O(nlogn) // introsort used

	sort(arr, arr + n);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	// 2. reversing a sequence using the built-in reverse()

	reverse(arr, arr + n);

	// reverse(arr + 1, arr + 4); // [1, 4)

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	// 3. reversing a sequence in-range using the built-in reverse()


	return 0;
}
