class Solution {
public:
    vector<vector<int>>dp;
    int solve(vector<int>&nums,int right,int n){
        if(n <= 0)return 0;
        if(dp[right][n]!=-1)return dp[right][n];
        int ans = 0;
        int  notTake = solve(nums,right,n-1);
        
        if((right == nums.size()) || nums[n-1] < nums[right]){
            ans = max(ans,1 + solve(nums,n-1,n-1));
        }
        ans = max({ans,notTake});
        return dp[right][n] = ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n+1,vector<int>(n+1,-1));
        int ans = solve(nums,n,n);
        return ans;
    }
};