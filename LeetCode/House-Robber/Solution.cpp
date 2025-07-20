class Solution {
public:
    vector<int>dp;
    int solve(vector<int>&nums,int n){
        if(n<=0)return 0;
        if(dp[n] != -1)return dp[n];
        int opt1 = nums[n-1] + solve(nums,n-2);
        int opt2 = solve(nums,n-1);
        return dp[n] = max(opt1,opt2);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n+1,-1);
        int ans = solve(nums,n);
        return ans;
    }
};