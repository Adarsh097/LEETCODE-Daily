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
    TreeNode* solve(vector<int>&pre,vector<int>&post,int &i,int s,int e){
        if(i>=pre.size() || s>e)return NULL;

        TreeNode* root = new TreeNode(pre[i]);
        i++;
        if(s==e)return root;

        int left = m[pre[i]];
        root->left = solve(pre,post,i,s,left);
        root->right = solve(pre,post,i,left+1,e-1);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = postorder.size();
        for(int i=0;i<n;i++){
            m[postorder[i]] = i;
        }
        int s = 0;
        TreeNode* root = solve(preorder,postorder,s,0,n-1);
        return root;
    }
};