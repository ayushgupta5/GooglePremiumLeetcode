/*272. Closest Binary Search Tree Value II
Given the root of a binary search tree, a target value, and an integer k, return the k values in the BST that are closest to the target. You may return the answer in any order.
You are guaranteed to have only one unique set of k values in the BST that are closest to the target.
Input: root = [4,2,5,1,3], target = 3.714286, k = 2
Output: [4,3]
Input: root = [1], target = 0.000000, k = 1
Output: [1]     */
class Solution {
public:
    void dfs(TreeNode* root, priority_queue<pair<double, int>>& pq, double target, int k) {
        if(!root) return;
        pq.push(make_pair(fabs(target - double(root->val)), root->val));
        if(pq.size() > k) pq.pop();
        dfs(root->left, pq, target, k);
        dfs(root->right, pq, target, k);
    }
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        priority_queue<pair<double, int>> pq;
        vector<int> result;
        dfs(root, pq, target, k);
        while(pq.size()) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};



