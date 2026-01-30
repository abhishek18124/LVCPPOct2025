/*

Given a string (sequence of characters) of length n, generate all of its permutations.

Example

	Input : inp[] = "abc"
	Output: ["abc", "acb", "bac", "bca", "cba", "cab"]

*/

#include<iostream>
#include<cstring>

using namespace std;

void f(char inp[], int n, int i) {

	// base case

	if (i == n) { // inp[i] == '\0'
		cout << inp << endl;
		return;
	}

	// recursive case

	// f(i) : take decisions for remaining slots i to n-1

	// decide that char to be assigned to the ith slot

	// swap(inp[i], inp[i]); f(i+1);
	// swap(inp[i], inp[i+1]); f(i+1);
	// swap(inp[i], inp[i+2]); f(i+1);
	// ...
	// swap(inp[i], inp[n-1]); f(i+1);

	// in general, swap(inp[i], inp[j]); i<=j<=n-1 f(i+1);

	for (int j = i; j < n; j++) {
		swap(inp[i], inp[j]);
		f(inp, n, i + 1);
		swap(inp[i], inp[j]); // backtracking // undo
	}

}

int main() {

	char inp[] = "aabc";
	int n = strlen(inp);

	f(inp, n, 0);

	return 0;
}
