class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n,1);
        int temp1 = 1, temp2 = 1;
        for(int i=1;i<nums.size();i++){
           temp1 *= nums[i-1];
           ans[i] *= temp1;

           temp2 *= nums[n-i];
           ans[n-i-1] *= temp2;


        }
        return ans;
    }
};