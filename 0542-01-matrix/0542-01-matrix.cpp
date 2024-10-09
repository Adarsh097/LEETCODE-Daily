class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        vector<vector<int>>dist(m,vector<int>(n,0));
        // {{r,c},dist}
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] == 0){
                    q.push({{i,j},0});
                    // mark the zero as visited to visit only ones in the bfs traversal
                    vis[i][j] = 1;
                }
            }
        }
        int row[4] = {1,0,-1,0};
        int col[4] = {0,1,0,-1};
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int d = q.front().second;
            q.pop();
            dist[r][c] = d;
            for(int i=0;i<4;i++){
                int nr = r + row[i];
                int nc = c + col[i];
                if(nr>=0 && nr<m && nc>=0 && nc<n && vis[nr][nc]==0){
                    //surely, it  is one
                    vis[nr][nc] = 1;
                    q.push({{nr,nc},d+1});
                }
            }
        }
        return dist;
    }
};