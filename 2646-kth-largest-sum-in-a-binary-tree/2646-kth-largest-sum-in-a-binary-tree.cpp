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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long ,vector<long long>,greater<long long>>pq;
        long long levelSum = 0;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node!=NULL){
                levelSum += node->val;
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }else{
                if(pq.size()<k)pq.push(levelSum);
                else if(levelSum>pq.top()){
                    pq.pop();
                    pq.push(levelSum);
                }
                levelSum = 0;
                if(!q.empty())q.push(NULL);
            }
        }
        if(pq.size()<k)return -1;
        return pq.top();
    }
};