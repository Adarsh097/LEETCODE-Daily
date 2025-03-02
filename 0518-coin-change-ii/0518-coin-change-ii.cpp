class Solution {
public:
    int solve(int amount,vector<int>&coins,int n, vector<vector<int>>&dp){
        if(n==0){
            // size of the array 
            return 0;
        }
        if(amount==0){
            return 1;
        }
        if(dp[n][amount] != -1){
            return dp[n][amount];
        }
        // options
        int ans = 0;
        if(amount>=coins[n-1]){
        ans += solve(amount-coins[n-1],coins,n,dp);
        ans += solve(amount,coins,n-1,dp);
        }else{
          ans +=  solve(amount,coins,n-1,dp);
        }
        return dp[n][amount] = ans;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        int ans = solve(amount,coins,n,dp);
        return ans;
    }
};