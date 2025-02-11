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
class Box{
    public:
    bool isBST=true;
    int sum = 0;
    int min = INT_MAX;
    int max = INT_MIN;
};
class Solution {
public:
    Box* solve(TreeNode* &root,int &ans){
        if(!root){
            return new Box();
        }

        Box* leftTree = solve(root->left,ans);
        Box* rightTree = solve(root->right,ans);

        if(leftTree->isBST && rightTree->isBST && root->val > leftTree->max && root->val < rightTree->min){
            // root is valid bst
            Box* head = new Box();
            head->sum = root->val + leftTree->sum + rightTree->sum;
            ans = max(ans,head->sum);

            head->min = min(root->val,leftTree->min);
            head->max = max(root->val,rightTree->max);
            return head;
        }else{
            rightTree->isBST = false;
            return rightTree;
        }
    }
    int maxSumBST(TreeNode* root) {
        int ans = 0;
        solve(root,ans);
        return ans;
    }
};