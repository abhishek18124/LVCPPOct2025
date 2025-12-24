#include<iostream>
#include<string>

using namespace std;

// for a string of size n, it contains n * (n+1) / 2 ~ n^2 substrings
// time : n^2.n ~ O(n^3)

void generateSubstrings(const string& str) { // by default str is passed by value

	int n = str.size();

	for (int i = 0; i < n; i++) {

		for (int j = i; j < n; j++) {

			// generate the substring that starts at the ith index
			// and ends at the jth index

			// for (int k = i; k <= j; k++) {

			// 	cout << str[k];

			// }

			// cout << endl;

			// string substring = str.substr(i, j - i + 1);
			// cout << substring << endl;

			cout << str.substr(i, j - i + 1) << endl;

		}

		cout << endl;

	}

}

int main() {

	string str = "abcde";

	generateSubstrings(str);

	return 0;
}