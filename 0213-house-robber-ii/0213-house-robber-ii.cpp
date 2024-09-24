class Solution {
public:
    int solve(vector<int>&nums,int s,int e,vector<int>&dp){
        // no house to loot
        if(s>=e){
            return 0;
        }
        if(dp[s] !=-1)return dp[s];

        int opt1 = nums[s] + solve(nums,s+2,e,dp);
        int opt2 = solve(nums,s+1,e,dp);
        return dp[s] = max(opt1,opt2);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return nums[0];
        vector<int>dp(n+1,-1);
        int rob1 = solve(nums,1,n,dp);

        vector<int>dp1(n+1,-1);
        int rob2 = solve(nums,0,n-1,dp1);

        return max(rob1,rob2);
    }
};