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
    void flatten(TreeNode* root) {
        if(!root)return;

        TreeNode* node = root;
        while(node){
            if(!node->left){
                node = node->right;
            }else{
                TreeNode* curr = node->left;
                while(curr->right){
                    curr = curr->right;
                }
                curr->right = node->right;
                node->right = node->left;
                node->left = NULL;
                node = node->right;
            }
        }
        return;
    }
};