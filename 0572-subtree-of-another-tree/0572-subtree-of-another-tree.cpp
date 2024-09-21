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
    bool ans;
    bool check(TreeNode* &root1, TreeNode* &root2){
        if(!root1 && !root2)return true;

        if((!root1 && root2) || (root1 && !root2))return false;

        bool curr = root1->val == root2->val;
        bool leftAns = check(root1->left,root2->left);
        bool rightAns = check(root1->right,root2->right);

        return curr && leftAns && rightAns;
    }
    void solve(TreeNode*&root, TreeNode*&subRoot){
        if(root==NULL)return;
        if(root->val == subRoot->val){
            bool x = check(root,subRoot);
            if(x)ans = true;
        }
        solve(root->left,subRoot);
        solve(root->right,subRoot);
        return;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        solve(root,subRoot);
        return ans;
    }
};