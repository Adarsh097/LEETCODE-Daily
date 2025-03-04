class Solution {
public:
    int MOD = 1e9 + 7;
    int m,n;
    vector<vector<vector<int>>>dp;
    int solve(vector<vector<int>>&grid,int &k,int i,int j,int sum){
        if(i>=m || j>=n)return 0;
        if(i==m-1 && j==n-1){
            return ((grid[i][j]+sum)%k)==0?1:0;
        }
        sum = (sum + grid[i][j])%k;
        if(dp[i][j][sum]!=-1)return dp[i][j][sum];


        
        int opt1 = solve(grid,k,i+1,j,sum);

        int opt2 = solve(grid,k,i,j+1,sum);

        return dp[i][j][sum] = (opt1 + opt2)%MOD;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        m = grid.size(), n = grid[0].size();
        dp.resize(m,vector<vector<int>>(n,vector<int>(k,-1)));
        int totalPaths = solve(grid,k,0,0,0);
        return totalPaths;
    }
};