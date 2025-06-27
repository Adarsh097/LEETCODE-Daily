class Solution {
public:
    vector<int>dp;
    int solve(int n){
        
        if(n==1)return 1;
        if(n==2)return 2;
        if(dp[n] != -1)return dp[n];

        int steps = solve(n-1) + solve(n-2);
        return dp[n] = steps;
    }
    int climbStairs(int n) {
        dp.resize(n+1,-1);
        int ans = solve(n);
        return ans;
    }
};