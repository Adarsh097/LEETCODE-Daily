class Solution {
public:
    int n;
    vector<vector<int>>arr;
    int dp[51][51][51][51];
    int solve(int i1,int j1,int i2,int j2){
        if(i1==n-1 && j1==n-1 && i2==n-1 && j2==n-1){
            return arr[n-1][n-1];
        }
        if(i1>=n || j1>=n || i2>=n || j2>=n || arr[i1][j1]==-1 || arr[i2][j2]==-1)return INT_MIN;

        if(dp[i1][j1][i2][j2]!=-1)return dp[i1][j1][i2][j2];

        int ans = 0;
        
        ans += (i1==i2 && j1==j2)?arr[i1][j1]:arr[i1][j1]+arr[i2][j2];

        int opt1 =solve(i1+1,j1,i2+1,j2);
        int opt2 = solve(i1+1,j1,i2,j2+1);
        int opt3 = solve(i1,j1+1,i2+1,j2);
        int opt4 = solve(i1,j1+1,i2,j2+1);

        return dp[i1][j1][i2][j2] = ans + max({opt1,opt2,opt3,opt4});
    }
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        arr = grid;
        memset(dp,-1,sizeof(dp));
        if(grid[0][0]==-1 || grid[n-1][n-1]==-1)return 0;
        int ans = solve(0,0,0,0);
        return (ans<0)?0:ans;
    }
};