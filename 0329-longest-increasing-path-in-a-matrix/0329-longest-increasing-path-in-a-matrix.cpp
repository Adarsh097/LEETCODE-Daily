class Solution {
public:
    vector<vector<int>>dp;
    int r[4] = {1,0,-1,0};
    int c[4] = {0,1,0,-1};
    int solve(int i,int j,int prev,vector<vector<int>>& matrix){
        if(i<0 || j<0 || i>=matrix.size() || j>=matrix[0].size()){
            return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int ans = 0;
        for(int k=0;k<4;k++){
            int row = i + r[k], col = j + c[k];
            if(row>=0 && col >=0 && row<matrix.size() && col<matrix[0].size() && matrix[row][col]>prev){
                int temp = 1 + solve(row,col,matrix[row][col],matrix);
                ans = max(temp,ans);
            }
        }
        return dp[i][j] = ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;
        dp.resize(m+1,vector<int>(n+1,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int temp = 1 + solve(i,j,matrix[i][j],matrix);
                ans = max(ans,temp);
            }
        }
        return ans;
    }
};