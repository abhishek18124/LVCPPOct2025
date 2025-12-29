/*

	Constraints

	0 < m, n <= 10

	here, m denotes the no. of rows in the given 2D array
	      n denotes the no. of cols in the given 2D array

*/

#include<iostream>

using namespace std;

int main() {

	int arr[10][10];

	int m;
	cin >> m;

	int n;
	cin >> n;

	// read mxn values into the 2D array

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	// print mxn values of the 2D array

	for (int i = 0; i < m; i++) { // iterate over rows
		// print ith row
		for (int j = 0; j < n; j++) { // iterate over col
			cout << arr[i][j] << " ";
		}
	}

	cout << endl;

	for (int j = 0; j < n; j++) { // iterate over cols
		// print the jth column
		for (int i = 0; i < m; i++) { // iterate over rows
			cout << arr[i][j] << " ";
		}
	}

	return 0;
}


