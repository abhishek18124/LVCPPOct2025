class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int s = nums[0];
        int f = nums[0];

        while (true) {

            s = nums[s];
            f = nums[nums[f]];

            if (s == f) {
                break;
            }

        }

        // at this point of time, s & f are at the meeting point

        s = nums[0];

        while (s != f) {

            s = nums[s];
            f = nums[f];

        }

        return s; // return f;

    }
};