class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        int r[4] = {1,0,-1,0};
        int c[4] = {0,1,0,-1};
        pq.push({grid[0][0],0,0});
        grid[0][0] = INT_MAX;
        int ans = 0;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int time = it[0], x = it[1], y = it[2];
            ans = max(ans,time);
            if(x==m-1 && y==n-1)break;
            for(int i=0;i<4;i++){
                int nx = x + r[i] , ny = y + c[i];
                if(nx<0 || ny<0 || nx>=m || ny>=n || grid[nx][ny]==INT_MAX)continue;      
                pq.push({grid[nx][ny],nx,ny});
                grid[nx][ny] = INT_MAX;
            }
        }
        return ans;
    }
};