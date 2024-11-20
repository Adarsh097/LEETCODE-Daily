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
    bool checkEqual(TreeNode* &root1 , TreeNode* &root2){
        if(!root1 && !root2)return true;
        if((!root1 && root2) || (root1 && !root2))return false;
        if(root1-> val != root2->val)return false;
        
        return checkEqual(root1->left,root2->left) && checkEqual(root1->right,root2->right);
    }
    void solve(TreeNode* &root,bool &ans,TreeNode* &subRoot){
        if(!root)return;
        if(root->val == subRoot->val){
            if(checkEqual(root,subRoot)){
                ans = true;
                return;
            }
            
        }
        solve(root->left,ans,subRoot);
        solve(root->right,ans,subRoot);
        return;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool ans = false;
        solve(root,ans,subRoot);
        return ans;
    }
};