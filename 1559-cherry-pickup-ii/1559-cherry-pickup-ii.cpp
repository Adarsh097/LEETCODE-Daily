class Solution {
public:
    int robCol1[9] = {0, 0, 0, -1, -1, -1, 1, 1, 1};
    int robCol2[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
    int m, n;
    vector<vector<int>> arr;
    int dp[71][71][71];
    int maxCherry(int i, int j1, int j2) {

        if (j1 < 0 || j1 >= n || j2 < 0 || j2 >= n)
            return INT_MIN;
        if (i == m - 1) {
            return (j1 == j2) ? arr[i][j1] : arr[i][j1] + arr[i][j2];
        }

        if(dp[i][j1][j2] != -1)return dp[i][j1][j2];

        int ans = (j1 == j2) ? arr[i][j1] : arr[i][j1] + arr[i][j2];
        int temp = 0;
        for (int ind = 0; ind < 9; ind++) {
            int col1 = j1 + robCol1[ind];
            int col2 = j2 + robCol2[ind];

            temp = max(temp, maxCherry(i + 1, col1, col2));
        }
        return dp[i][j1][j2] = ans + temp;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        memset(dp,-1,sizeof(dp));
        arr = grid;
        return maxCherry(0, 0, n - 1);
    }
};