/*549. Binary Tree Longest Consecutive Sequence II
Given the root of a binary tree, return the length of the longest consecutive path in the tree.
A consecutive path is a path where the values of the consecutive nodes in the path differ by one. This path can be either increasing or decreasing.
For example, [1,2,3,4] and [4,3,2,1] are both considered valid, but the path [1,2,4,3] is not valid.
On the other hand, the path can be in the child-Parent-child order, where not necessarily be parent-child order.
Input: root = [1,2,3]
Output: 2
Explanation: The longest consecutive path is [1, 2] or [2, 1].
Input: root = [2,1,3]
Output: 3
Explanation: The longest consecutive path is [1, 2, 3] or [3, 2, 1].
*/
class Solution {
public:
    int longestConsecutive(TreeNode* root) {        
        int ans = 0;
        TreeNode* parent = NULL;
        helper(root, parent, ans);   
        return ans;
    }
    pair<int,int> helper(TreeNode* root, TreeNode*& parent, int& ans) {
        if (!root) return {0,0};
        pair<int,int> left = helper(root->left, root, ans);
        pair<int,int> right = helper(root->right, root, ans);
        ans = max(ans, left.first + right.second + 1);
        ans = max(ans, left.second + right.first + 1);
        int inc = 0, dec = 0;
        if (parent && root->val == parent->val + 1) {
            inc = max(left.first, right.first) + 1;
        }
        if (parent && root->val == parent->val -1) {
            dec = max(right.second, left.second) + 1;
        }
        return {inc, dec};
    }
};



