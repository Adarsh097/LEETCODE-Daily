class Solution {
public:
    vector<int>ans;
    vector<int>vis;
    bool isSafe(int &color,unordered_map<int,vector<int>>&m,int &node,int &n){
        for(auto &neigh : m[node]){
            if(vis[neigh]==color)return false;
        }
        return true;
    }
    bool solve(int node,int &n,unordered_map<int,vector<int>>&m){
        if(node==n){
            ans = vis;
            return true;
        }

        for(int i=1;i<=4;i++){
            if(isSafe(i,m,node,n)){
                vis[node] = i;
                if(solve(node+1,n,m))return true;
                vis[node] = 0;
            }
        }
        return false;
    }

    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
      
        vis.resize(n,0);
        unordered_map<int,vector<int>>m;
        
        for(auto &it: paths){
            int i = it[0]-1, j = it[1]-1;
            m[i].push_back(j);
            m[j].push_back(i);
        }
        solve(0,n,m);
        return ans;

    }
};