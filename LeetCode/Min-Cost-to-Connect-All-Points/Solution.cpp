class DisJoint{
    public:
    vector<int>par,size;
    DisJoint(int n){
        par.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            par[i] = i;
        }
    }

    int find(int node){
        if(par[node]==node)return node;
        return par[node] = find(par[node]);
    }

    void findUnion(int u,int v){
        int up = find(u), vp = find(v);
        if(up == vp)return ;
        if(size[up]>=size[vp]){
            par[vp] = up;
            size[up] += size[vp];
        }else{
            par[up] = vp;
            size[vp] += size[up];
        }
        return;
    }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>>arr;
        int n = points.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int dist = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                arr.push_back({dist,i,j});
            }
        }
        sort(arr.begin(),arr.end());
        DisJoint ds(n);
        int cost = 0;
        for(auto &it : arr){
            int val = it[0], up = ds.find(it[1]), vp = ds.find(it[2]);
            if(up != vp){
                cost += val;
                ds.findUnion(up,vp);
            }
        }
        return cost;
        
    }
};