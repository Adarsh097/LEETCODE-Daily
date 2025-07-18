class Solution {
public:
    vector<vector<int>>dp;
    int solve(int amount, vector<int>& coins,int n){
        if(amount==0)return 1;
        if(amount < 0 || n == 0)return 0;
        if(dp[n][amount]!=-1)return dp[n][amount];

        int opt1 = solve(amount,coins,n-1);
        int opt2 = solve(amount-coins[n-1],coins,n);
        return dp[n][amount] = opt1 + opt2;
    }
    int change(int amount, vector<int>& coins) {
     int n = coins.size();
     dp.resize(n+1,vector<int>(amount+1,-1));
     int ans = solve(amount,coins,n);
     return ans;   
    }
};