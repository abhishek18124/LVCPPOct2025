#include<iostream>
#include<string>

using namespace std;

int main() {

	string str = "cbaeicdeiou";

	int cnt = 0; // to track the count of consecutive vowels
	int maxSoFar = 0; // to track the length of the longest good substring

	// time : O(n)
	// space: O(1)

	for (char ch : str) {

		if (ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u') {

			cnt++;
			maxSoFar = max(maxSoFar, cnt);

		} else {

			cnt = 0;

		}

	}

	cout << maxSoFar << endl;

	return 0;
}