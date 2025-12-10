/*

e.g.

input
9
1 0 1 2 0 1 2 0 1

output
0 0 0 1 1 1 1 2 2

*/

#include<iostream>
#include<vector>

using namespace std;

int main() {

	vector<int> arr = {1, 0, 1, 2, 0, 1, 2, 0, 1};
	int n = arr.size();

	int low = 0;
	int mid = 0;
	int high = n - 1;

	// time : O(n)
	// space: O(1)

	/*

	arr[0..low-1] -> zeros
	arr[low...mid-1] -> ones
	arr[mid...high] -> unknown
	arr[high+1...n-1] -> twos

	*/

	while (mid <= high) {
		if (arr[mid] == 0) {
			// put arr[mid] in zeros
			swap(arr[mid], arr[low]);
			low++;
			mid++;
		} else if (arr[mid] == 1) {
			mid++;
		} else {
			// arr[mid] == 2
			swap(arr[mid], arr[high]);
			high--;
		}
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;


	return 0;

}