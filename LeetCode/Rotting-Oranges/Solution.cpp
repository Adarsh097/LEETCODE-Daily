class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int,int>>q;
        int days = 0, total = 0, cnt = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0){
                    total++;
                    if(grid[i][j]==2)q.push({i,j});
                }
            }
        }
        int r[4] = {1,0,-1,0};
        int c[4] = {0,1,0,-1};
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                auto it = q.front();
                q.pop();
                cnt++;
                for(int k=0;k<4;k++){
                    int newRow = it.first + r[k], newCol = it.second + c[k];
                    if(newRow<0 || newCol <0 || newRow>=m || newCol >=n || grid[newRow][newCol]!=1)continue;
                    grid[newRow][newCol] = 2;
                    q.push({newRow,newCol});
                }
            }
            if(!q.empty())days++;
        }
        return (total==cnt)?days:-1;
    }
};