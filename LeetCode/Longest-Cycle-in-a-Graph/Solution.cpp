class Solution {
public:
    int ans = -1;
    void dfs(int node, vector<int>&vis, vector<int>&path, vector<int>&dist,vector<int>& edges){
        if(node !=-1){
            vis[node] = 1;
            path[node] = 1;
            int v = edges[node];
            if(v!=-1 && !vis[v]){
                dist[v] = dist[node] + 1;
                dfs(v,vis,path,dist,edges);
            }
            else if(v!=-1 && vis[v]){
                if(path[v]==1){
                    //cycle 
                    ans = max(ans,dist[node]-dist[v] + 1);
                }
            }
            path[node] = 0;
        }
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int>vis(n,0);
        vector<int>path(n,0);
        vector<int>dist(n,1);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,path,dist,edges);
            }
        }
        return ans;
    }
};