#include<iostream>
#include<vector>
#include<stack>

using namespace std;

// time : O(n)
// space: O(n) due to monotonic stack

vector<int> f(const vector<int>& A) {

	int n = A.size();
	vector<int> ans(n, -1);
	stack<int> s; // monotonic stack // <index>

	for (int i = 0; i < n; i++) {

		// for what element(s) A[i] can be the nearest greater element
		// to their right

		while (!s.empty() and A[i] > A[s.top()]) {
			// A[i] is the nearest greater element to the right
			// of A[s.top()]
			ans[s.top()] = A[i];
			s.pop();

		}

		s.push(i);

	}

	return ans;

}

int main() {

	vector<int> A = {5, 3, 6, 7, 2, 1, 4};

	vector<int> ans = f(A);
	for (int x : ans) {
		cout << x << " ";
	}
	cout << endl;

	return 0;
}