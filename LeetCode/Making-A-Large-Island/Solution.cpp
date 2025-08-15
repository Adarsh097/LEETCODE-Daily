class Disjoint {
public:
    vector<int> size, par;
    Disjoint(int n) {
        size.resize(n + 1, 1);
        par.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            par[i] = i;
        }
    }

    int find(int node) {
        if (par[node] == node)
            return node;
        return par[node] = find(par[node]);
    }

    void findUnion(int u, int v) {
        int up = find(u), vp = find(v);
        if (up == vp)
            return;

        if (size[up] >= size[vp]) {
            par[vp] = up;
            size[up] += size[vp];
        } else {
            par[up] = vp;
            size[vp] += size[up];
        }
        return;
    }
};
class Solution {
public:
    bool check(int r, int c, int n) {
        return (r >= 0 && c >= 0 && r < n && c < n);
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int r[4] = {1, 0, -1, 0};
        int c[4] = {0, 1, 0, -1};

        Disjoint ds(n * n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int node = i * n + j;
                    for (int k = 0; k < 4; k++) {
                        int nr = i + r[k], nc = j + c[k];
                        if (check(nr, nc, n) && grid[nr][nc] == 1) {
                            int newNode = nr * n + nc;
                            ds.findUnion(node, newNode);
                        }
                    }
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    set<int>s;
                
                    for (int k = 0; k < 4; k++) {
                        int nr = i + r[k], nc = j + c[k];
                        if (check(nr, nc, n) && grid[nr][nc] == 1) {
                            int newNode = nr * n + nc;
                            int parent = ds.find(newNode);
                            s.insert(parent);
                        }
                    }
                    int area = 0;
                    for(auto &it : s){
                        area += ds.size[it];
                    }
                    ans = max(ans,area+1);
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int node = i*n + j;
                    ans = max(ans,ds.size[ds.par[node]]);
                }
            }
        }
        return ans;
    }
};