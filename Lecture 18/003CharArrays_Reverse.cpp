#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int main() {

	char str[] = "hello";

	cout << str << endl;

	int n = strlen(str);

	// reverse(str, str + n); // reverses str[] from [0, n)

	reverse(str + 1, str + 4); // reverses str[] from [1, 4)

	cout << str << endl;

	return 0;
}