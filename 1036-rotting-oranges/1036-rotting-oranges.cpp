class Solution {
public:
    int row[4] = {1,0,-1,0};
    int col[4] = {0,1,0,-1};
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
       
        //{{row,col},timeOfInsertion}
        queue<pair<pair<int,int>,int>>q;

        //push all the rotten oranges at time = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 2){
                    //rotten
                    q.push({{i,j},0});
                }
            }
        }

        // find the total time
         int time = 0;
         while(!q.empty()){
            auto it = q.front();
            q.pop();
            int r = it.first.first;
            int c = it.first.second;
            int t = it.second;
            time = max(time,t);

            for(int i=0;i<4;i++){
                int nr = r + row[i];
                int nc = c + col[i];
                if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]==1){
                    q.push({{nr,nc},t+1});
                    grid[nr][nc] = 2;
                }

            }
         }

           for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    //rotten
                   return -1;
                }
            }
        }
        return time;
    }
};