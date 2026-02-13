#include<iostream>
#include<stack>
#include<vector>

using namespace std;

vector<int> f(const vector<int>& A) {

	stack<int> s; // monotonic stack // <index>
	vector<int> ans;

	int n = A.size();

	for (int i = 0; i <= n - 1; i++) {

		// find the index nearest smaller element to the
		// left of A[i] in const time using monotonic stack

		while (!s.empty() and A[s.top()] >= A[i]) {
			s.pop();
		}

		if (s.empty()) {
			// there is no smaller element to the left of A[i]
			ans.push_back(-1);
		} else {
			// whatever is at the top of the stack is the idx
			// of nearest smaller element to the left of A[i]
			ans.push_back(s.top());
		}

		s.push(i);

	}

	return ans;

}

int main() {

	vector<int> A = {0, 3, 5, 4, 1, 6, 2};

	vector<int> ans = f(A);
	for (int x : ans) {
		cout << x << " ";
	}
	cout << endl;

	return 0;
}