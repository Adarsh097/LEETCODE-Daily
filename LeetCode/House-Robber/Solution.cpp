class Solution {
public:
    int solveR(vector<int>&nums,int n){
        if(n==0)return 0;
        if(n==1)return nums[0];

        int opt1 = nums[n-1] + solveR(nums,n-2);
        int opt2 = 0 + solveR(nums,n-1);

        int ans = max(opt1,opt2);
        return ans;

    }
    int solveM(vector<int>&nums,int n,vector<int>&dp){
        if(n==0)return 0;
        if(n==1)return nums[0];
        if(dp[n]!=-1)return dp[n];
        int opt1 = nums[n-1] + solveM(nums,n-2,dp);
        int opt2 = 0 + solveM(nums,n-1,dp);

        dp[n] = max(opt1,opt2);
        return dp[n];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        // int ans = solveR(nums,n);

        vector<int>dp(n+1,-1);
        int ans = solveM(nums,n,dp);
        return ans;
    }
};