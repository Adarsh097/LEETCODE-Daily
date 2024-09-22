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
    unordered_map<TreeNode*,int>m;
    int rob(TreeNode* root) {
        if(m.find(root) !=m.end()){
            return m[root];
        }
        if(root==nullptr) return 0;

        int ll = 0;
        int lr = 0;
        int rl = 0;
        int rr = 0;

        if(root->left){
            ll = rob(root->left->left);
            lr = rob(root->left->right);
        }
        if(root->right){
            rl = rob(root->right->left);
            rr = rob(root->right->right);
        }
        int curr = root->val + ll + lr + rl + rr;

        int l = rob(root->left);
        int r = rob(root->right);

        int withoutCurr = l + r;

        return m[root] =  max(curr,withoutCurr);


    }
};