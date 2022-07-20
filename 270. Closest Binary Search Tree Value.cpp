/*270. Closest Binary Search Tree Value(Premium)
Given the root of a binary search tree and a target value, return the value in the BST that is closest to the target.
Input: root = [4,2,5,1,3], target = 3.714286
Output: 4
Input: root = [1], target = 4.428571
Output: 1
*/
class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        int a = root->val;
        auto kid = target < a ? root->left : root->right;
        if (!kid) return a;
        int b = closestValue(kid, target);
        return abs(a - target) < abs(b - target) ? a : b;
    }
/*----------------------------------------------------------------------------------------*/
    int closestValue(TreeNode* root, double target) {
        double mini=1e9, ans, val;
        stack<TreeNode *> st;
        while(root || st.size()) {
            while(root) {
                st.push(root);
                root=root->left;
            }
            root=st.top(); st.pop();
            val=root->val;
            if(mini>abs(val-target)) {
                mini=abs(val-target);
                ans=val;
            }
            root=root->right;
        }
        return int(ans);
    }
};

