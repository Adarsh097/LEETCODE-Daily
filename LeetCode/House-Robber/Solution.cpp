class Solution {
public:
    int solveRecursion(vector<int>&nums,int n,vector<int>&dp){
        // if the index is negative then, array is invalid so, no house for robbing
        if(n<0)return 0;
        //only one house for the robbing
        if(n==0) return nums[0];

        //value already exists
        if(dp[n]!=-1){
            return dp[n];
        }

        //include
        int include=nums[n] + solveRecursion(nums,n-2,dp);
        //exclude
        int exclude= 0 + solveRecursion(nums,n-1,dp);
        //storing the ans
        dp[n] = max(include,exclude);
        return dp[n];
    }
    int rob(vector<int>& nums) {
        int n=nums.size()-1;
        //creating the vector array
        vector<int>dp(n+1,-1);
        int ans=solveRecursion(nums,n,dp);
        return ans;
    }
};