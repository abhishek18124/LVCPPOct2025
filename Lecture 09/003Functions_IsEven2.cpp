#include<iostream>

using namespace std;

bool isEven(int n) {

	// if (n % 2 == 0) {
	// 	return true;
	// } else {
	// 	return false;
	// }

	// if (n % 2 == 0) {
	// 	return true;
	// }

	// return false;

	// return n % 2 == 0 ? true : false;

	return n % 2 == 0;

}

int main() {

	bool ans;

	ans = isEven(4); // a fn call that returns a value can be treated as an expr

	cout << ans << endl;

	ans = isEven(5);

	cout << ans << endl;

	cout << isEven(7) << endl;

	if (isEven(9)) {
		cout << "even" << endl;
	} else {
		cout << "odd" << endl;
	}

	isEven(11) ? cout << "even" << endl : cout << "odd" << endl;

	return 0;
}