#include<iostream>
#include<vector>
#include<stack>

using namespace std;

// time : O(n)
// space: O(n)

vector<int> f(const vector<int>& A) {

	vector<int> ans;
	stack<pair<int, int>> s; // monotonic stack // <value, index>
	int n = A.size();

	for (int i = 0; i < n; i++) {

		// find the index of the nearest greater element
		// to the left of A[i] in const time using monotonic
		// stack

		while (!s.empty() and s.top().first <= A[i]) {
			s.pop();
		}

		int j;
		if (s.empty()) {
			// there is no greater element to the left of A[i]
			j = -1;
		} else {
			// whatever is at the top of the stack is the
			// nearest greater element of the left of A[i]
			j = s.top().second;
		}

		ans.push_back(i - j);

		s.push({A[i], i});

	}

	return ans;

}

int main() {

	vector<int> A = {100, 80, 60, 70, 60, 75, 85, 200};

	vector<int> ans = f(A);
	for (int x : ans) {
		cout << x << " ";
	}
	cout << endl;

	return 0;
}