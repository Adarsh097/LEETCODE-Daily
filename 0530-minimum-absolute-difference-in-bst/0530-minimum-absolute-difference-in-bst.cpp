/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int prev = 300000;
    int ans = INT_MAX;
    void solve(TreeNode* &root){
        if(!root)return;
        solve(root->left);
        int curr = root->val;
        ans = min(abs(curr-prev),ans);
        prev = curr;
        solve(root->right);
        return;

    }
    int getMinimumDifference(TreeNode* root) {
        solve(root);
        return ans;
    }
};