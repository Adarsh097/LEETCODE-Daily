1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
8 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
9 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
10 * };
11 */
12class Solution {
13public:
14    vector<int>result;
15    vector<int> rightSideView(TreeNode* root) {
16        solve(root,0);
17        return result;
18    }
19    void solve(TreeNode* root, int depth){
20        if(!root)return;
21
22        if(depth==result.size()){
23            result.push_back(root->val);
24        }
25
26        solve(root->right,depth+1);
27        solve(root->left,depth+1);
28        return;
29    }
30};