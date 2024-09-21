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
  
    void solve(TreeNode* &root, int &k,int &ans){
        if(root==NULL)return;
        //left part
        solve(root->left,k,ans);
        //process
        k--;
        if(k==0)ans = root->val;
        // right part
        solve(root->right,k,ans);

    }
    int kthSmallest(TreeNode* root, int k) {
        int ans = INT_MAX;
        solve(root,k,ans);
        return ans;
    }
};