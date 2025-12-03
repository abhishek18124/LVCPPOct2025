#include<iostream>
#include<vector>

using namespace std;

int main() {

	int n;
	cin >> n;

	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int serejaScore = 0;
	int dimaScore = 0;

	int i = 0;
	int j = n - 1;

	bool serejasTurn = true;

	while (i <= j) {

		if (serejasTurn) {

			// it is sereja's turn

			if (arr[i] > arr[j]) {

				// sereja will pick the leftmost active card

				serejaScore += arr[i];
				i++;

			} else {

				// sereja will pick the rightmost active card

				serejaScore += arr[j];
				j--;

			}

			serejasTurn = false;

		} else {

			// it is dima's turn

			if (arr[i] > arr[j]) {

				// dima will pick the leftmost active card

				dimaScore += arr[i];
				i++;

			} else {

				// dima will pick the rightmost active card

				dimaScore += arr[j];
				j--;

			}

			serejasTurn = true;

		}

	}

	cout << serejaScore << " " << dimaScore << endl;

	return 0;
}