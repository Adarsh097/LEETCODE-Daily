#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));

        // Store queries along with their original index
        vector<pair<int, int>> qrr;
        for (int i = 0; i < queries.size(); i++) {
            qrr.push_back({queries[i], i});
        }
        sort(qrr.begin(), qrr.end()); // Sort queries in increasing order

        // Min-Heap (Priority Queue) to process grid cells
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        pq.push({grid[0][0], {0, 0}});
        vis[0][0] = 1;

        vector<int> ans(queries.size(), 0);
        int count = 0, ind = 0;

        int row[4] = {1, 0, -1, 0};
        int col[4] = {0, 1, 0, -1};

        while (ind < queries.size()) {
            int val = qrr[ind].first;
            int queryIndex = qrr[ind].second;

            // Process all reachable cells with values < current query value
            while (!pq.empty() && pq.top().first < val) {
                auto it = pq.top();
                pq.pop();
                count++;

                int i = it.second.first, j = it.second.second;
                for (int k = 0; k < 4; k++) {
                    int r = i + row[k], c = j + col[k];
                    if (r >= 0 && r < m && c >= 0 && c < n && !vis[r][c]) {
                        vis[r][c] = 1;
                        pq.push({grid[r][c], {r, c}});
                    }
                }
            }

            // Store the result for this query
            ans[queryIndex] = count;
            ind++;
        }

        return ans;
    }
};
