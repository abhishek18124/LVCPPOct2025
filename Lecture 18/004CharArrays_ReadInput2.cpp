// constraints n <= 100

#include<iostream>

using namespace std;

int main() {

	char str[101]; // based on constraints

	cin.getline(str, 101);

	cout << str;

	// 1. cin.getline() stops reading at EOF / '\n'
	// 2. cin.getline() reads leading and non-leading whitespaces
	// 3. we can optionally pass a delimiting char while calling cin.getline()

	return 0;
}