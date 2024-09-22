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
    unordered_map<int,int>m;
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int s,int e,int &ind){
        if(ind >= inorder.size() || s>e){
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[ind++]);

        int pos = m[root->val];

        root->left = solve(preorder,inorder,s,pos-1,ind);
        root->right = solve(preorder,inorder,pos+1,e,ind);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for(int i=0;i<n;i++){
            m[inorder[i]] = i;
        }
        int s = 0;
        int e = n-1;
        int ind = 0;
        TreeNode* root = solve(preorder,inorder,s,e,ind);
        return root;
    }
};