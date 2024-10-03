class Solution {
public:
    unordered_map<int,vector<int>>adj;
    vector<int>vis;
    void dfs(int node){
        vis[node] = 1;

        for(auto &neigh : adj[node]){
            if(!vis[neigh]){
                dfs(neigh);
            }
        }
        return;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int totalNodes = isConnected.size();

        // making the adjacency list
        for(int i=0;i<totalNodes;i++){
            for(int j=0;j<totalNodes;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        // find the provinces
        vis.resize(totalNodes,0);
        int totalProvinces = 0;

        for(int i=0;i<totalNodes;i++){
            if(!vis[i]){
                dfs(i);
                totalProvinces++;
            }
        }
        return totalProvinces;
    }
};