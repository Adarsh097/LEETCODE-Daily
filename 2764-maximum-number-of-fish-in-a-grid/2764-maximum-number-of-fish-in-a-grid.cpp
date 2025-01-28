class Solution {
public:
    int r[4] = {-1, 0, 1, 0};
    int c[4] = {0, -1, 0, 1};
    void solve(vector<vector<int>>& grid, int i, int j, int& temp) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() ||
            grid[i][j] == 0)
            return;
        temp += grid[i][j];
        grid[i][j] = 0;
        for (int k = 0; k < 4; k++) {
            solve(grid, i + r[k], j + c[k], temp);
        }
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0) {
                    int temp = 0;
                    solve(grid, i, j, temp);
                    ans = max(ans, temp);
                }
            }
        }
        return ans;
    }
};