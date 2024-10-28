class Solution {
public:
    vector<int>dp;
    int solveM(int n){
        if(n==0){
            // one possible way to reach here
            return 1;
        }
        if(n==1){
            //one step to reach the place
            return 1;
        }
        if(dp[n] !=-1 )return dp[n];
        dp[n] = solveM(n-1) + solveM(n-2);
        return dp[n];
    }
    int climbStairs(int n) {
        dp.resize(n+1,-1);
        int ans = solveM(n);
        return ans;
    }
};