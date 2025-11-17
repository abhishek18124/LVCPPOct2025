#include<iostream>

using namespace std;

int main() {

	int cnt = 0; // to track the no. of characters read before '$'

	char ch;

	while (true) {

		// cin >> ch; // cin >> skips / ignores whitespaces (' ', '\t', '\n')

		ch = cin.get(); // cin.get() reads whitespaces as well

		if (ch == '$') {
			break;
		}

		cnt++;

	}

	cout << "cnt = " << cnt << endl;

	return 0;
}