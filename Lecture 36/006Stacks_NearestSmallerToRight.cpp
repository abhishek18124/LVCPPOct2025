#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;

// time : O(n)
// space: O(n) due to the monotonic stack

vector<int> f(const vector<int>& A) {

	stack<int> s; // monotonic stack // <index>
	vector<int> ans;

	int n = A.size();

	for (int i = n - 1; i >= 0; i--) {

		// find the index nearest smaller element to the
		// right of A[i] in const time using monotonic stack

		while (!s.empty() and A[s.top()] >= A[i]) {
			s.pop();
		}

		if (s.empty()) {
			// there is no smaller element to the right of A[i]
			ans.push_back(n);
		} else {
			// whatever is at the top of the stack is the idx
			// of nearest smaller element to the right of A[i]
			ans.push_back(s.top());
		}

		s.push(i);

	}

	reverse(ans.begin(), ans.end());

	return ans;

}


int main() {

	vector<int> A = {2, 5, 1, 3, 6, 4, 0};

	vector<int> ans = f(A);
	for (int x : ans) {
		cout << x << " ";
	}
	cout << endl;

	return 0;
}