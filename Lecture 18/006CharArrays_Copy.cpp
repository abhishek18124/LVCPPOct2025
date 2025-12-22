#include<iostream>
#include<cstring>

using namespace std;

int main() {

	char s1[100] = "abcde";
	char s2[] = "xyz";

	cout << s1 << endl; // abcde

	strcpy(s1, s2); // we are copying s2 into s1

	cout << s1 << endl; // xyz

	return 0;
}