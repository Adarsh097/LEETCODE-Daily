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
    int solve(TreeNode*&root,int &ans){
        if(root==NULL){
            return 1;
        }
        int l = solve(root->left,ans);
        int r = solve(root->right,ans);

        if(l==-1 || r==-1){
            ans++;
            return 0;
        }
        else if(l==0 || r==0){
            return 1;
        }else{
            return -1;
        }
    }
    int minCameraCover(TreeNode* root) {
        int ans = 0;
        int flag = solve(root,ans);
        
        if(flag == -1)ans++;
        return ans;
    }
};