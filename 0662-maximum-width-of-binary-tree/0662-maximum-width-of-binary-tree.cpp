/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL)
            return 0;

        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});
        unsigned long long maxWidth = 0;

        while (!q.empty()) {
            unsigned long long n = q.size();
            unsigned long long startPos = q.front().second;
            unsigned long long first, last;
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front().first;
                unsigned long long pos = q.front().second;
                q.pop();
                if(i==0)first = pos;
                if(i==n-1)last = pos;

                if(node->left)q.push({node->left,(2*pos)+1});
                if(node->right)q.push({node->right,(2*pos) + 2});
                
            }
            maxWidth  = max(maxWidth,last-first+1);
        }
        return maxWidth;
    }
};