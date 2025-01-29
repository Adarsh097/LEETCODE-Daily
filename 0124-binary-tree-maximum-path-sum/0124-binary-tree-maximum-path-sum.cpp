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
    int solve(TreeNode* &root){
        if(!root)return 0;

        int lH = solve(root->left);
        int rH = solve(root->right);

        int temp = max(max(lH,rH)+root->val , root->val);
        int result = max(temp,lH+rH+root->val);
        ans = max(ans,result);
        return temp;
    }
    int maxPathSum(TreeNode* root) {
        solve(root);
        return ans;
    }
};