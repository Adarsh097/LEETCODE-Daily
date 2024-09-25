class Solution {
public:
    vector<vector<int>>dp;
    int solve(int m, int n){
        if(m==0 && n==0){
            // one way to reach here
            return 1;
        }
        if(m<0 || n<0){
            //out of bound
            return 0;
        }
        if(dp[m][n] != -1)return dp[m][n];

        int opt1 = solve(m-1,n);
        int opt2 = solve(m,n-1);

        return dp[m][n] = opt1 + opt2;
    }
    int uniquePaths(int m, int n) {
        dp.resize(m,vector<int>(n,-1));
        int ans = solve(m-1,n-1);
    
        return ans;
    }
};