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
    int solve(TreeNode*&root, int &result){
          // base case
        if(root==nullptr)return 0;


        // hypothesis
        int leftAns = solve(root->left,result);
        int rightAns = solve(root->right,result);


        // induction
        int temp = max(leftAns,rightAns) + 1;
        int ans = max(temp,leftAns+rightAns+1);
        result = max(ans,result);
        return temp;

    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)return 0;
       int ans = INT_MIN;
       solve(root,ans);
       return ans-1;

    }
};