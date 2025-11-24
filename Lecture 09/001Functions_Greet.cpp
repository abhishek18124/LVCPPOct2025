#include<iostream>

using namespace std;

void greet() {
	cout << "hello world" << endl;
	return; // optional
}

int main() {

	cout << "I am inside main(), yet to call greet" << endl;

	greet(); // function call or function invocation

	cout << "I am inside main(), after calling greet" << endl;

	return 0;
}

