class Solution {
public:
    int row[4] = {1,0,-1,0};
    int col[4] = {0,1,0,-1};
    
    void count(vector<vector<char>>& grid,int i,int j){
        grid[i][j] = '0';
        for(int k=0;k<4;k++){
            int r = i + row[k];
            int c = j + col[k];
            if(r<0 || c<0 || r>=grid.size() || c>=grid[0].size() || grid[r][c]=='0')continue;
            
                count(grid,r,c);
            
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    cnt++;
                    count(grid,i,j);
                }
            }
        }
        return cnt;
    }
};