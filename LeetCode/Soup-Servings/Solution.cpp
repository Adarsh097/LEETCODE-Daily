class Solution {
public:
     vector<vector<double>> dp;
    double solve(int A, int B){
        if(A<=0 && B<=0)return 0.5;
        if(A<=0)return 1.0;

        if(B<=0)return 0.0;
        if(dp[A][B]!=-1.0)return dp[A][B];

        double ans = 0.0;
        ans += solve(A-100,B);
        ans += solve(A-75,B-25);
        ans += solve(A-50,B-50);
        ans += solve(A-25,B-75);
        return dp[A][B] = ans*0.25;
    }
    double soupServings(int n) {
        if(n>=5000)return 1.0;
        dp.resize(n+1,vector<double>(n+1,-1.0));
        return solve(n,n);
    }
};