#include<iostream>

using namespace std;

int main() {

	char str[] = {'a', 'b', 'c', 'd', 'e', '\0'};
	cout << str << endl;

	for (int i = 0; str[i] != '\0'; i++) {
		cout << str[i] << endl;
	}

	char str2[] = "coding";
	cout << str2 << endl;

	for (int i = 0; str2[i] != '\0'; i++) {
		cout << str2[i] << endl;
	}

	return 0;
}
