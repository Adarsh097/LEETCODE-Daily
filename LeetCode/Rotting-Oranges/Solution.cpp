class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), days = 0, cnt = 0, total = 0;
        queue<pair<int,int>>q;//{i,j}

        int row[4] = {1,0,-1,0};
        int col[4] = {0,1,0,-1};

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] != 0)total++;
                if(grid[i][j] == 2)q.push({i,j});
            }
        }

        while(!q.empty()){
            int size = q.size();

            while(size--){// one level
                int x = q.front().first, y = q.front().second;
                q.pop();
                cnt++;

                for(int i=0;i<4;i++){
                    int r = x + row[i];
                    int c = y + col[i];

                    if(r<0 || c<0 || r>=m || c>=n || grid[r][c]!=1)continue;

                    grid[r][c] = 2;
                    q.push({r,c});
                }

            }

            if(!q.empty())days++;

        }

        return total==cnt?days:-1;
        
    }
};