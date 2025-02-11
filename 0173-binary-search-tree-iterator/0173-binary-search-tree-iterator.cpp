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
class BSTIterator {
    vector<int>arr;
    int n;
    int it;
public:
    void inorder(TreeNode* &root){
        if(root==NULL)return;
        inorder(root->left);
        arr.push_back(root->val);
        inorder(root->right);
        return;
    }
    BSTIterator(TreeNode* root) {
        inorder(root);
        it = -1;
        n = arr.size();
    }
    
    int next() {
        it++;
        return arr[it];
    }
    
    bool hasNext() {
        if(it<n-1)return true;
        else return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */