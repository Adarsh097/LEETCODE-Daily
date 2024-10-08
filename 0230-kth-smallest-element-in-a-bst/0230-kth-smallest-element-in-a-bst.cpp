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
    int ans;
    void solve(TreeNode* &root, int &k){
        if(root==NULL)return;
        //left part
        solve(root->left,k);
        //process
        k--;
        if(k==0)ans = root->val;
        // right part
        solve(root->right,k);

    }
    int kthSmallest(TreeNode* root, int k) {
        solve(root,k);
        return ans;
    }
};