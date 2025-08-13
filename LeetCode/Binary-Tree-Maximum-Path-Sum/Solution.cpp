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
    int ans = INT_MIN;
    int solve(TreeNode* root){
        if(!root)return 0;
        int lh = solve(root->left);
        int rh = solve(root->right);

        int temp = max(max(lh,rh)+root->val,root->val);
        int curr = max(temp,lh+rh+root->val);
        ans = max(ans,curr);
        return temp;
    }
    int maxPathSum(TreeNode* root) {
        solve(root);
        return ans;
    }
};