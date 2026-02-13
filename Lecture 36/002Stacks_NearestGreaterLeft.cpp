#include<iostream>
#include<vector>
#include<stack>

using namespace std;

// time : O(n)
// space: O(n) due to the monotonic stack

vector<int> f(const vector<int>& A) {

	stack<int> s; // monotonic stack
	vector<int> ans;

	int n = A.size();

	for (int i = 0; i <= n - 1 ; i++) {

		// find the nearest greater element to the
		// left of A[i] in const time using monotonic stack

		while (!s.empty() and s.top() <= A[i]) {
			s.pop();
		}

		if (s.empty()) {
			// there is no greater element to the left of A[i]
			ans.push_back(-1);
		} else {
			// whatever is at the top of the stack is the
			// nearest greater element to the left of A[i]
			ans.push_back(s.top());
		}

		s.push(A[i]);

	}

	return ans;

}

int main() {

	vector<int> A = {5, 2, 0, 4, 1, 3, 6};

	vector<int> ans = f(A);
	for (int x : ans) {
		cout << x << " ";
	}
	cout << endl; // -1 5 2 5 4 4 -1

	return 0;
}