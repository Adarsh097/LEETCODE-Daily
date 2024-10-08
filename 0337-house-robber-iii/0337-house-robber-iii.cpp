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
    map<TreeNode*,int>m;
    int rob(TreeNode* root) {
        if(m.find(root) != m.end()){
            // root is present
            return m[root];
        }
        if(!root)return 0;

        int ll = 0,lr = 0, rl = 0, rr = 0;
        if(root->left){
            ll = rob(root->left->left);
            lr = rob(root->left->right);
        }
        if(root->right){
            rl = rob(root->right->left);
            rr = rob(root->right->right);
        }

        int l = rob(root->left);
        int r = rob(root->right);

        int withRoot = root->val + ll + lr + rl + rr;

        return m[root] = max(withRoot,l+r);
    }
};