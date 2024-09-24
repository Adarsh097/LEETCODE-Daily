class Solution {
public:
    vector<vector<int>>dp;
    int solve(int amount, vector<int>& coins,int n){
        if(amount==0)return 1;
        if(amount < 0)return 0;
        if(n <=0 )return 0;

        if(dp[amount][n] !=-1)return dp[amount][n];
        int ans = 0;
        if(coins[n-1] <= amount){
            int opt1 = solve(amount-coins[n-1],coins,n);
            
            ans += opt1;
        }
        int opt2 = solve(amount,coins,n-1);
        ans +=opt2;
        return dp[amount][n] = ans;

    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        dp.resize(amount+1,vector<int>(n+1,-1));
        int ans = solve(amount,coins,n);
        return ans;
    }
};