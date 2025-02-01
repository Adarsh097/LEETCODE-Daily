class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();

        vector<vector<int>>vis(m,vector<int>(n,0));
        vector<vector<int>>dist(m,vector<int>(n,-1));

        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(isWater[i][j]==1){
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
            }
        }
        int x[4] = {1,0,-1,0};
        int y[4] = {0,1,0,-1};
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int row = it.first.first;
            int col = it.first.second;
            int d = it.second;
            dist[row][col] = d;

            for(int i=0;i<4;i++){
                int r = x[i] + row;
                int c = y[i] + col;

                if(r<0 || r>=m || c<0 || c>=n || vis[r][c]==1)continue;

                vis[r][c] = 1;
                q.push({{r,c},d+1});
            }


        }
        return dist;

    }
};