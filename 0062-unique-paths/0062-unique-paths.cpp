class Solution {
public:
    vector<vector<int>>dp;
    int solve(int m,int n){
        if(m==0 && n==0)return 1;

        if(m<0 || n<0)return 0;

        if(dp[m][n]!=-1) return dp[m][n];

        int up = solve(m-1,n);
        int down = solve(m,n-1);

        return dp[m][n] = up + down;
    }
    int uniquePaths(int m, int n) {
        dp.resize(m,vector<int>(n,-1));
        int ans = solve(m-1,n-1);
        return ans;
    }
};