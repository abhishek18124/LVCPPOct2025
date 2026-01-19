#include<iostream>

using namespace std;

int f(string str, int n) {

	// base case

	if (str.empty()) { // str == "" // n == 0 // str.size() == 0
		return 0;
	}

	// recursive case

	string substring = str.substr(0, n - 1);
	int integerFromMyFriend = f(substring, n - 1);

	return integerFromMyFriend * 10 + (str[n - 1] - '0');

}

int main() {

	string str = "12345";
	int n = str.size();

	cout << f(str, n) << endl;

	return 0;
}