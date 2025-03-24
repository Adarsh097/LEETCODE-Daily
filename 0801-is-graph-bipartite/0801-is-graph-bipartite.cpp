class Solution {
public:
    vector<int>color;
    bool check(vector<vector<int>>&graph,int node,int col){
        color[node] = col;

        for(auto &neigh : graph[node]){
            if(color[neigh]==-1){
                if(!check(graph,neigh,!col))return false;
            }else if(color[node]==color[neigh])return false;
            
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        color.assign(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
            if(!check(graph,i,0)){
                return false;
            }
            }
        }
        return true;
    }
};