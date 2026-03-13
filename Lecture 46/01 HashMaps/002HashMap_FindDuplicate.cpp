// https://leetcode.com/problems/find-the-duplicate-number/description/

class Solution {
public:
	int findDuplicate(vector<int>& nums) {

		while (true) {
			int x = nums[0];
			if (nums[x] == x) {
				return x;
			}
			swap(nums[0], nums[x]);
		}

	}
};