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
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder,int s,int e,int &pos, unordered_map<int,int>&m){
        if(s>e || pos<0){
            return NULL;
        }

        TreeNode* root = new TreeNode(postorder[pos--]);

        int ind  = m[root->val];
        root->right = solve(inorder,postorder,ind+1,e,pos,m);
        root->left = solve(inorder,postorder,s,ind-1,pos,m);
        return root;
        
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
         unordered_map<int,int>m;
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]] = i;
        }
        int n = inorder.size();
        int s = 0;
        int e = n-1;
        int pos = n-1;
        TreeNode* ans = solve(inorder,postorder,s,e,pos,m);
        return ans;
    }
};