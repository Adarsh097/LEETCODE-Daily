class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // all positves -> consider  all
        // even negatives -> consider all
        // odd negatives -> leave one negative and consider all
        // contains zero
      
        int product = INT_MIN;
        int prev = 1;
        int suff = 1;
        int n = nums.size();
        for(int i=0;i<n;i++){
            prev = prev * nums[i];
            suff = suff * nums[n-1-i];
            product = max({product,prev,suff});
            if(prev == 0)prev = 1;
            if(suff == 0)suff = 1;
        } 
        return product;
    }
};