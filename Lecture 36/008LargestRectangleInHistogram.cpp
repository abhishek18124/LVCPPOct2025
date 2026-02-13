#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

class Solution {
public:

	vector<int> f1(const vector<int>& A) {

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

	vector<int> f2(const vector<int>& A) {

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

	// time : O(n)
	// space: O(n) due to monotonic stack in f1, f2

	int largestRectangleArea(vector<int>& heights) {

		int n = heights.size();

		vector<int> nsr = f1(heights); // linear
		vector<int> nsl = f2(heights); // linear

		int maxSoFar = 0;

		for (int i = 0; i < n; i++) { // linear
			// find the area of the largest rectangle you can form
			// whose height is equal to heights[i]
			int bestWidth = nsr[i] - nsl[i] - 1;
			int bestArea = heights[i] * bestWidth;
			maxSoFar = max(maxSoFar, bestArea);
		}

		return maxSoFar;

	}
};

int main() {

	vector<int> heights = {2, 1, 5, 6, 2, 3};
	Solution s;

	cout << s.largestRectangleArea(heights) << endl;

	return 0;
}