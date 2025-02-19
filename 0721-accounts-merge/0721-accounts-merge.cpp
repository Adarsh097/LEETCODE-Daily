class DisjointSet{
    public:
    vector<int>parent,rank;

    DisjointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }

    int findUP(int node){
        if(node == parent[node])return node;
        return parent[node] = findUP(parent[node]);
    }

    void UnionByRank(int u,int v){
        int parU = findUP(u);
        int parV = findUP(v);
        if(parU == parV)return;

        if(rank[parU]<rank[parV]){
            parent[parU] = parV;
        }else if(rank[parV]<rank[parU]){
            parent[parV] = parU; 
        }else{
            parent[parU] = parV;
            rank[parV]++;
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,int>m;
        int n = accounts.size();
          DisjointSet ds(n);
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string em = accounts[i][j];
                if(m.find(em)==m.end()){
                    m[em] = i;
                }else{
                    ds.UnionByRank(i,m[em]);
                }
            }
        }

        vector<string> arr[n];
        for(auto &it : m){
            string mail = it.first;
            int node = it.second;
            int parent = ds.findUP(node);
            arr[parent].push_back(mail);

        }
         vector<vector<string>> ans;
         for(int i=0;i<n;i++){
            if(arr[i].size()==0)continue;
            sort(arr[i].begin(),arr[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto &em : arr[i]){
                temp.push_back(em);
            }
            ans.push_back(temp);
         }
         return ans;
    }
};