#include<iostream>
#include<string>

using namespace std;

bool isGoodString(const string& str) {

	for (char ch : str) {

		if (!(ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u')) {

			// str is not a good string

			return false;

		}

	}

	// str is a good string

	return true;

}

// time : O(n^3)
// space: O(1)

int longestGoodSubstring(const string& str) {

	int n = str.size();
	int maxSoFar = 0; // to track the length of the longest good substring

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			// check if the substring that starts at the ith index
			// and ends at the jth index is good or not
			string subString = str.substr(i, j - i + 1);
			if (isGoodString(subString)) {
				// subString is good, track its length
				maxSoFar = max(maxSoFar, j - i + 1);
			}
		}
	}

	return maxSoFar;

}

int main() {

	string str = "cbaeicdeiou";
	cout << longestGoodSubstring(str) << endl;

	return 0;
}