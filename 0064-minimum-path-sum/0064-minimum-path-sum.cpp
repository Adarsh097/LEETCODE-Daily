class Solution {
public:
    vector<vector<int>> dp;
    int findMinPathSum(vector<vector<int>>& grid, int m, int n) {
        if (m == 0 && n == 0) {
            return grid[m][n];
        }

        if (m < 0 || n < 0)
            return 10000000;
        if (dp[m][n] != -1)
            return dp[m][n];
        int opt1 = grid[m][n] + findMinPathSum(grid, m - 1, n);
        int opt2 = grid[m][n] + findMinPathSum(grid, m, n - 1);
        return dp[m][n] = min(opt1, opt2);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size() - 1;
        int n = grid[0].size() - 1;

        // dp.resize(m+1,vector<int>(n+1,-1));
        // int minSum = findMinPathSum(grid, m, n);
        // return minSum;

        /* TABULATION */
        // vector<vector<int>> arr(m + 1, vector<int>(n + 1, 0));
        // arr[0][0] = grid[0][0];
        // //  can go right only
        // for (int col = 1; col < n + 1; col++) {
        //     arr[0][col] = arr[0][col - 1] + grid[0][col];
        // }
        // // can go down only
        // for (int row = 1; row < m + 1; row++) {
        //     arr[row][0] = arr[row - 1][0] + grid[row][0];
        // }

        // for (int i = 1; i < m + 1; i++) {
        //     for (int j = 1; j < n + 1; j++) {
        // int opt1 = grid[i][j] + arr[i - 1][j];
        // int opt2 = grid[i][j] + arr[i][j - 1];
        // arr[i][j] = min(opt1, opt2);
        //     }
        // }
        // return arr[m][n];

        /* SO */
        vector<int> prev(n + 1, 0);
        vector<int> curr(n + 1, 0);
        prev[0] = grid[0][0];
        for (int col = 1; col < n + 1; col++) {
            prev[col] = prev[col - 1] + grid[0][col];
        }
        for (int i = 1; i < m + 1; i++) {
            for (int j = 0; j < n + 1; j++) {
                if (j == 0) {
                    curr[j] = grid[i][j] + prev[j];
                } else {
                    int opt1 = grid[i][j] + prev[j];
                    int opt2 = grid[i][j] + curr[j - 1];
                    curr[j] = min(opt1, opt2);
                }
            }
            prev = curr;
        }
        return prev[n];
    }
};