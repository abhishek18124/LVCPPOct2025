// constraints : n <= 100

#include<iostream>

using namespace std;

int partition(int arr[], int s, int e) {

	int p = arr[e];

	int j = s;
	int i = s;

	while (j < e) {

		if (arr[j] <= p) {

			// put arr[j] in the left partition

			swap(arr[i], arr[j]);
			i++;
			j++;

		} else {

			// arr[j] > p

			// put arr[j] in the right partition

			j++;

		}

	}

	swap(arr[i], arr[e]);

	return i;


}

void f(int arr[], int s, int e) {

	// base case

	if (s > e) { // mandatory
		return;
	}

	if (s == e) { // optional
		return;
	}

	// recursive case

	// f(s, e) : sort arr[s...e] using the quick sort algo.

	int pidx = partition(arr, s, e);
	f(arr, s, pidx - 1);
	f(arr, pidx + 1, e);

}

int main() {

	int arr[] = {60, 50, 20, 10, 40, 30};
	int n = sizeof(arr) / sizeof(int);

	f(arr, 0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}