#include<iostream>

using namespace std;

string f(int n) {

	// base case

	if (n == 0) {
		// f(0) : generate the binary string for 0
		return "";
	}

	// recursive case

	// f(n) : generate the binary string for n

	// 1. ask your friend to generate the binary string for n/2

	string answerFromMyFriend = f(n / 2);

	// 2. use the answer given by your friend to solve the org. problem

	int remainder = n % 2;

	return answerFromMyFriend + to_string(remainder);

}

int main() {

	int n;
	cin >> n;

	cout << f(n) << endl;

	return 0;
}