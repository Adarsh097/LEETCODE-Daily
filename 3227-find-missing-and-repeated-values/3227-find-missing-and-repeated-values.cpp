class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int>ans;
        vector<int>vis(n*n,0);
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
               vis[grid[i][j]-1]++;
            }
        }
        for(int i=0;i<n*n;i++){
            if(vis[i]==0)ans.push_back(i+1);
            if(vis[i]==2)ans.insert(ans.begin(),i+1);
        }
        return ans;
        
    }
};