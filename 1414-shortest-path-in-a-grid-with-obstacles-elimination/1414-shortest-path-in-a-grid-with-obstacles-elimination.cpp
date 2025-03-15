#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

class Solution {
public:
    int row[4] = {1, 0, -1, 0};
    int col[4] = {0, 1, 0, -1};

    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        if (grid[0][0] == 1 && k == 0) return -1;

        queue<tuple<int, int, int, int>> q;
        vector<vector<vector<bool>>> vis(m, vector<vector<bool>>(n, vector<bool>(k + 1, false)));

        if (grid[0][0] == 1) k--;
        vis[0][0][k] = true;
        q.push({0, 0, 0, k});
        int ans = INT_MAX;
        while (!q.empty()) {
            auto [dist, r, c, remK] = q.front();
            q.pop();

            if (r == m - 1 && c == n - 1 && dist<ans) ans =  dist; 

            for (int i = 0; i < 4; i++) {
                int x = r + row[i], y = c + col[i];
                if (x >= 0 && y >= 0 && x < m && y < n) {
                    int newK = remK - grid[x][y];
                    if (newK >= 0 && !vis[x][y][newK]) {
                        vis[x][y][newK] = true;
                        q.push({dist + 1, x, y, newK});
                    }
                }
            }
        }
        return (ans==INT_MAX)?-1:ans;
    }
};
