/*
	https://leetcode.com/problems/longest-consecutive-sequence/
*/

#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:

	// time : O(nlogn)
	// space: O(n)

	int longestConsecutive(vector<int>& nums) {

		map<int, bool> startMap;

		for (int num : nums) {

			if (startMap.find(num - 1) == startMap.end()) {
				// we've not seen num-1 so far so for now we can assume num to be a starting point
				startMap[num] = true;
			} else {
				// we've seen num-1 previously so num cannot be a starting point
				startMap[num] = false;
			}

			if (startMap.find(num + 1) != startMap.end()) {
				// we've previously seen num+1 and now that we've seen num, num+1 can no longer be a starting point
				startMap[num + 1] = false;
			}

		}

		// for (auto [num, status] : startMap) {
		// 	cout << num << " : " << status << endl;
		// }

		int maxSofar = 0;

		for (pair<int, bool> p : startMap) {

			int num = p.first;
			bool status = p.second;

			if (status == 1) {

				// find the length of the sequence of
				// consecutive elements that start with
				// 'num'

				int cnt = 0;

				while (startMap.find(num) != startMap.end()) {
					cnt++;
					num++;
				}

				maxSofar = max(maxSofar, cnt);

			}

		}

		return maxSofar;

	}
};

int main() {

	Solution s;

	vector<int> nums = {0, 1, 4, 5, 6, 11, 12, 13, 14};

	cout << s.longestConsecutive(nums) << endl;

}
