
#include<iostream>
#include<queue>

using namespace std;

class Solution {
public:

    // time : O(n)
    // space: 26 due to freqMap + 26 due to minHeap : O(1)

    string reorganizeString(string s) {

        int freq[26] = {0};
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        priority_queue<pair<int, char>> maxHeap;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                maxHeap.push({freq[i], i + 'a'});
                // maxHeap.push(make_pair(freq[i], i+'a'));
            }
        }

        // while (!maxHeap.empty()) {
        //     pair<int, char> p = maxHeap.top();
        //     maxHeap.pop();
        //     cout << p.first << " " << p.second << endl;
        // }

        string ans = "";

        while (!maxHeap.empty()) {

            if (maxHeap.size() == 1) {
                pair<int, char> lastPair = maxHeap.top();
                maxHeap.pop();
                if (lastPair.first == 1) {
                    ans += lastPair.second;
                } else {
                    // lastPair.first > 1
                    ans = "";
                }
            } else {
                // maxHeap.size() >= 2
                pair<int, char> firstMaxPair = maxHeap.top();
                maxHeap.pop();

                pair<int, char> secondMaxPair = maxHeap.top();
                maxHeap.pop();

                ans += firstMaxPair.second;
                firstMaxPair.first--;

                ans += secondMaxPair.second;
                secondMaxPair.first--;

                if (firstMaxPair.first > 0) {
                    maxHeap.push(firstMaxPair);
                }

                if (secondMaxPair.first > 0) {
                    maxHeap.push(secondMaxPair);
                }

            }

        }

        return ans;

    }
};

int main() {

    Solution soln;
    string s = "aab";

    cout << soln.reorganizeString(s) << endl;

    return 0;
}