#include<iostream>
#include<string>

using namespace std;

// time : O(n)
// space: O(1)

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

int main() {

	string str = "uoxea";

	isGoodString(str) ? cout << "good string" << endl : cout << "not good string" << endl;

	return 0;
}