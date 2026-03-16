// https://leetcode.com/problems/sliding-window-maximum/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {

		// todo ...

	}
};


int main() {

	vector<int> nums = {1, 4, 0, 1, 2, 3, 5};
	int k = 4;

	Solution s;

	vector<int> ans = s.maxSlidingWindow(nums, k);

	for (int x : ans) {
		cout << x << " ";
	}

	cout << endl;

	return 0;
}