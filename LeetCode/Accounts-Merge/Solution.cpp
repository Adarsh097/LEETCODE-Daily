class Disjoint{
    public:
    vector<int>size,parent;

    Disjoint(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }
    int find(int node){
        if(node == parent[node])return node;
        return parent[node] =  find(parent[node]);
    }

    void merge(int u,int v){
        int up = find(u), vp = find(v);
        if(up == vp)return;

        if(size[up] < size[vp]){
            parent[up] = vp;
            size[vp] += size[up];
        }else{
            parent[vp] = up;
            size[up] += size[vp];
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        unordered_map<string,int>m;
        Disjoint ds(n);
        for(int i=0;i<n;i++){

            for(int j=1;j<accounts[i].size();j++){
                string em = accounts[i][j];
                if(m.find(em)==m.end()){
                    m[em] = i;
                }else{
                    ds.merge(i,m[em]);
                }
            }
        }

        unordered_map<int,vector<string>>list;
        for(auto &it: m){
            string em = it.first; int p = it.second;
            int up = ds.find(p);
            list[up].push_back(em);
        }

        vector<vector<string>>ans;
        for(int i=0;i<n;i++){
            if(list[i].size()==0)continue;
            vector<string>t;
            t.push_back(accounts[i][0]);
            sort(list[i].begin(),list[i].end());
            for(auto &em: list[i]){
                t.push_back(em);
            }
            ans.push_back(t);
        }

        return ans;
    }
};