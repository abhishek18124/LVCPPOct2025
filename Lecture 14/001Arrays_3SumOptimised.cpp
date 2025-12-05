class Solution {
public:

	// time : O(nlogn + n^2) : O(n^2)

	vector<vector<int>> threeSum(vector<int>& nums) {
		int n = nums.size();

		sort(nums.begin(), nums.end());

		vector<vector<int>> ans;

		for (int i = 0; i <= n - 3; i++) {

			if (nums[i] > 0) {
				// there is no scope of finding nums[j], nums[k]
				// in nums[i+1...n-1] with the sum -nums[i] so we
				// can stop prematurely
				break;
			}

			if (i > 0 and nums[i] == nums[i - 1]) {
				continue;
			}

			// fix nums[i] as the 1st element of a potential

			// and now look for a pair (nums[j], nums[k]) in nums[i+1....n-1]

			// whose sum is equal to -nums[i]

			// nums[i] + nums[j] + nums[k] = 0
			// nums[j] + nums[k] = -nums[i]

			int t = -nums[i];
			int j = i + 1;
			int k = n - 1;

			while (j < k) {

				int pairSum = nums[j] + nums[k];
				if (pairSum == t) {
					// you've found a valid triplet
					ans.push_back({nums[i], nums[j], nums[k]});
					j++;
					k--;

					while (j < k and nums[j] == nums[j - 1]) {
						j++;
					}

					while (j < k and nums[k] == nums[k + 1]) {
						k--;
					}

				} else if (pairSum > t) {
					k--;
				} else {
					// pairSum < t
					j++;
				}

			}

		}

		return ans;

	}
};