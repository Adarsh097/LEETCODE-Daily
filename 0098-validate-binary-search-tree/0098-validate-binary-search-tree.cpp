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
    /* 
        1. here, value of the root can be upto -> INT_MIN or INT_MAX
        2. You should take greater range for the min and max range values.
     */
    bool solve(TreeNode* &root, long min, long max){
        if(root==NULL)return true;

         if(root->val < max && root->val > min){
            bool leftAns = solve(root->left,min,root->val);
            bool rightAns = solve(root->right,root->val,max);
            return leftAns && rightAns;
        }
        return false;
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL || (root->left==NULL && root->right==NULL))return true;
      bool ans = solve(root,LONG_MIN,LONG_MAX);
      return ans;
    }
};