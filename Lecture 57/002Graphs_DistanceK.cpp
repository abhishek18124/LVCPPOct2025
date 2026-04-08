/**
 * https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
 *
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    vector<int> bfs(int s, int k, map<int, vector<int>>& adj, set<int>& vis) {

        queue<int> q;
        q.push(s);

        map<int, int> distMap;
        distMap[s] = 0;

        vis.insert(s);

        while (!q.empty()) {

            int cur = q.front(); q.pop();
            for (int ngb : adj[cur]) {
                if (vis.find(ngb) == vis.end()) {
                    vis.insert(ngb);
                    q.push(ngb);
                    distMap[ngb] = distMap[cur] + 1;
                }
            }

        }

        vector<int> ans;

        for (auto [node, dist] : distMap) {
            if (dist == k) {
                ans.push_back(node);
            }
        }

        return ans;

    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        // 1. transform the binary tree into an undirected graph

        queue<TreeNode*> q;
        q.push(root);

        map<int, vector<int>> adj;

        while (!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            if (cur->left != NULL) {
                q.push(cur->left);
                adj[cur->val].push_back(cur->left->val);
                adj[cur->left->val].push_back(cur->val);
            }
            if (cur->right != NULL) {
                q.push(cur->right);
                adj[cur->val].push_back(cur->right->val);
                adj[cur->right->val].push_back(cur->val);
            }

        }

        // 2. solve the sssp with target node as the source

        int s = target->val;
        set<int> vis;

        return bfs(s, k, adj, vis);

    }
};