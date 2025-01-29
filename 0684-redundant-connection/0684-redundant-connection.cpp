class Solution {
public:
    bool check(int node,int v,unordered_map<int,vector<int>>&adj,vector<int>&vis){
        vis[node] = 1;
        if(node==v)return true;
        for(auto &neigh : adj[node]){
            if(!vis[neigh]){
                if(check(neigh,v,adj,vis))return true;
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>m;
        int n = edges.size();
      
        for(auto &it : edges){
            int u = it[0], v = it[1];
            if(m.find(u)!=m.end() && m.find(v)!=m.end()){
                  vector<int>vis(n+1,0);
                if(check(u,v,m,vis))return {u,v};
            }
            m[u].push_back(v);
            m[v].push_back(u);
        }
        return {-1,-1};
    }
};