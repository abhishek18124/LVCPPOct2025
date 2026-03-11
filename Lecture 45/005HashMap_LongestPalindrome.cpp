#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

int lenghOfLongestPalindrome(const string& str) {

	set<char> s;
	int cnt = 0;

	string leftStr = "";
	string rightStr = "";

	for (char ch : str) {

		if (s.find(ch) == s.end()) {

			s.insert(ch);

		} else {

			leftStr += ch;
			rightStr += ch;

			s.erase(ch);
			cnt += 2;

		}

	}

	reverse(rightStr.begin(), rightStr.end());

	if (!s.empty()) {
		cnt++;
		char ch = *s.begin();
		cout << leftStr + string(1, ch) + rightStr << endl;
	} else {
		cout << leftStr + rightStr << endl;
	}

	return cnt;

}

int main() {

	string str = "abcdd"; // abc.cba

	cout << lenghOfLongestPalindrome(str) << endl;

	return 0;
}