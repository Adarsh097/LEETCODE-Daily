class Solution {
public:
    struct trieNode{
        trieNode* left;
        trieNode* right;
    };

    void insert(trieNode* &root,int &num){
        trieNode* pcrawl = root;
        for(int i=31;i>=0;i--){
            int ith_bit = (num>>i)&1;

            if(ith_bit==1){
                if(!pcrawl->right){
                    pcrawl->right = new trieNode();
                }
                pcrawl = pcrawl->right;
            }else{
                if(!pcrawl->left){
                    pcrawl->left = new trieNode();
                }
                pcrawl = pcrawl->left;
            }
        }
        return;
    }

    int findMaxXor(int &num,trieNode* &root){
        trieNode* pcrawl = root;

        int mXor = 0;
        for(int i=31;i>=0;i--){
            int ith_bit = (num>>i)&1;

            if(ith_bit==1){
                if(pcrawl->left){
                    mXor += pow(2,i);
                    pcrawl = pcrawl->left;
                }else{
                    pcrawl = pcrawl->right;
                }
            }else{
                if(pcrawl->right){
                    mXor += pow(2,i);
                    pcrawl = pcrawl->right;
                }else{
                    pcrawl = pcrawl->left;
                }
            }
        }
        return mXor;
    }

    int findMaximumXOR(vector<int>& nums) {
        struct trieNode* root = new trieNode();

        for(auto &num : nums){
            insert(root,num);
        }

        int maxXor = 0;
        for(auto &num : nums){
            int temp = findMaxXor(num,root);
            maxXor = max(maxXor,temp);
        }
        return maxXor;
    }
};

//T -> O(log(maxNum)*n) : O(32*n)