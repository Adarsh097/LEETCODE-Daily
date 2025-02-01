class Solution {
public:
    unordered_map<int,vector<int>>adj;
    vector<vector<int>>bridges;
    int timer = 1;
    void dfs(int node, int parent, vector<int>&vis, vector<int>&tin,vector<int>&low){
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;

        for(auto &it : adj[node]){
    
            if(it == parent)continue;

            if(!vis[it]){
                dfs(it,node,vis,tin,low);
                low[node] = min(low[node],low[it]);

                if(low[it] > tin[node]){
                    bridges.push_back({node,it});
                }
            }else{
                low[node] = min(low[it],low[node]);
            }


        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        for(auto &it : connections){
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>vis(n,0);
        vector<int>tin(n,0);
        vector<int>low(n,0);
        dfs(0,-1,vis,tin,low);
        return bridges;
    }
};