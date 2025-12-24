#include<iostream>
#include<string>

using namespace std;

bool isPalindrome(const string& substring) {

	int i = 0;
	int j = substring.size() - 1;

	while (i < j) {

		if (substring[i] != substring[j]) {
			// substring is not a palindrome
			return false;
		}

		i++;
		j--;

	}

	// substring is a palindrome
	return true;

}

// time : O(n^3)
// space: O(1)

int countPalindromicSubstrings(const string& s) {

	int cnt = 0; // to track the no. of palindromic substrings in the given string

	int n = s.size();

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			// check if the substring that starts at the ith index
			// and ends at the jth index is a palindromic substring
			string substring = s.substr(i, j - i + 1);
			if (isPalindrome(substring)) {
				cnt++;
			}
		}
	}

	return cnt;

}

int main() {

	string s = "abaaba";

	cout << countPalindromicSubstrings(s) << endl;

	return 0;
}