class Solution {
public:

    bool f(const vector<int>& bloomDay, int m, int k, int timeLimit) { // time : O(n)
        // can I make 'm' bouquets of 'k' adjacent flowers in 'timeLimit' no. of days ?
        int cnt = 0; // to track no. of adj. flowers picked
        for (int curFlowerBloomDay : bloomDay) {
            if (curFlowerBloomDay <= timeLimit) {
                // pick the current flower as it is bloomed
                cnt++;
                if (cnt == k) {
                    // you've managed to make a bouquet
                    m--;
                    cnt = 0;
                    if (m == 0) {
                        // you've managed to make m bouquets of k adjacent flowers
                        return true;
                    }
                }
            } else {
                // you cannot pick the current flower as it not bloomed
                cnt = 0;
            }
        }

        // you were not able to make m bouqeuts of k adjacent flower
        // in the given timeLimit
        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int s = *min_element(bloomDay.begin(), bloomDay.end());
        int e = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;
        while (s <= e) { // time : O(n * log(e-s))
            int mid = s + (e - s) / 2;
            // can I make 'm' bouquets of 'k' adjacent flowers in 'mid' no. of days ?
            if (f(bloomDay, m, k, mid)) {
                // yes, I can make 'm' bouquets of 'k' adjacent flowers in 'mid' no. of days
                ans = mid;
                // reduce the search space from [s, e] to [s, mid-1]
                e = mid - 1;
            } else {
                // I cannot make 'm' bouquets of 'k' adjacent flowers in 'mid' no. of days
                // reduce the search space from [s, e] to [mid+1, e]
                s = mid + 1;
            }
        }
        return ans;
    }
};