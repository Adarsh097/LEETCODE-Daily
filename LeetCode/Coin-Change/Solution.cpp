class Solution {
public:
    vector< vector<int>>dp;
    int solve(int amount,int n,vector<int>&coins){
        if(amount==0)return 0;
        if(amount < 0 || n<=0)return 1e5;
        if(dp[n][amount] != -1)return dp[n][amount];

        int opt1 = solve(amount,n-1,coins);
        int opt2 = 1 + solve(amount-coins[n-1],n,coins);
        return dp[n][amount] = min(opt1,opt2);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        dp.resize(n+1,vector<int>(amount+1,-1));
        int ans =solve(amount,n,coins);
        return ans==1e5?-1:ans;
    }
};