class Solution {
public:
    int row[4] = {1,0,-1,0};
    int col[4] = {0,1,0,-1};
    void dfs(vector<vector<char>>& grid,int i,int j){
        grid[i][j] = '0';
        for(int k=0;k<4;k++){
            int r = i + row[k], c = j + col[k];
            if(r>=0 && c>=0 && r<grid.size() && c<grid[0].size() &&  grid[r][c] == '1'){
                dfs(grid,r,c);
            }
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    dfs(grid,i,j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};