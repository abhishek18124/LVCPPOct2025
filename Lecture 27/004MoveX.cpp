/*

Given a string str, design a recursive algorithm to move all the occurrence of letter x
to the end of the string str.

Example
	Input : str = "axbcxdxfx"
	Output: str = "abcdfxxxx"

	Input : str = "xabcxdxfx"
	Output: str = "abcdfxxxx"

*/

#include<iostream>

using namespace std;

string f(string str) {

	// base case

	if (str.empty()) { // str = "" // str.size() == 0
		return "";
	}

	// recursive case

	string substring = str.substr(1);
	string answerFromMyFriend = f(substring);

	if (str[0] == 'x') {
		return answerFromMyFriend + string(1, str[0]);
	} else {
		return string(1, str[0]) + answerFromMyFriend;
	}

}

int main() {

	string str = "axbxcx";

	cout << f(str) << endl; // abcxxx

	return 0;
}