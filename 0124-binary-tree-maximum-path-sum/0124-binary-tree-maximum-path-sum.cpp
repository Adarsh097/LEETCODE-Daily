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
    int solve(TreeNode* &root,int &sum){
        //b
        if(root==NULL)return 0;

        //h
        int leftAns = solve(root->left,sum);
        int rightAns = solve(root->right,sum);

        //i
        int temp = max(max(leftAns,rightAns)+root->val,root->val);
        int ans = max(temp,leftAns+rightAns+root->val);
        sum = max(sum,ans);
        return temp;

    }
    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN;
        solve(root,sum);
        return sum;
    }
};