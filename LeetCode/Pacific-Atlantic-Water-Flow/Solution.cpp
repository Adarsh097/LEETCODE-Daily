class Solution {
public:
     
      int r[4] = {1,0,-1,0};
      int c[4] = {0,1,0,-1};
    void dfs(int i,int j,vector<vector<int>>& heights,vector<vector<int>>&vis){
        vis[i][j]=1;
        for(int k=0;k<4;k++){
            int nr = i + r[k], nc = j + c[k];
            if(nr <0 || nc < 0 || nr == heights.size() || nc == heights[0].size() || vis[nr][nc]==1 || heights[nr][nc]<heights[i][j])continue;
            vis[nr][nc] = 1;
            dfs(nr,nc,heights,vis);
        }
    }
  
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
         vector<vector<int>>pac(m,vector<int>(n,0));
         vector<vector<int>>alt(m,vector<int>(n,0));
  
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || j==0 ){
                    dfs(i,j,heights,pac);
                }
            }
        }
        
           for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==m-1 || j==n-1 ){
                    dfs(i,j,heights,alt);
                }
            }
        }
    
        vector<vector<int>>ans;
         for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pac[i][j]==1 && alt[i][j]==1){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
