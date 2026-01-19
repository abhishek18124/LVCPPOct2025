#include<iostream>

using namespace std;

// time : (2^n - 1).const ~ O(2^n)

void f(int n, char src, char dst, char hlp) {

	// base case

	if (n == 0) {
		return;
	}

	// recursive case

	// f(n) : gen. steps to move n disks from
	// src to dst using hlp w/o any violations

	// 1. ask your friend to move n-1 disks from
	// src to hlp using dst w/o any violations

	f(n - 1, src, hlp, dst);

	// 2. move disk from src to dst

	cout << "move disk from " << src << " to " << dst << endl;

	// 3. ask your friend to move n-1 disks from
	// hlp to dst using src w/o any violations

	f(n - 1, hlp, dst, src);

}

int main() {

	int n;
	cin >> n;

	f(n, 'A', 'C', 'B');

	return 0;
}