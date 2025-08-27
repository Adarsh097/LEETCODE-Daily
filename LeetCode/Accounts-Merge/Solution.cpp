class DisjointSet {
public:
    vector<int> parent;
    vector<int> size;

    DisjointSet(int n) {
        parent.resize(n + 1);
        size.assign(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUP(int node) {
        if (parent[node] == node) return node;
        return parent[node] = findUP(parent[node]);
    }

    void unionBySize(int u, int v) {
        int up = findUP(u), vp = findUP(v);
        if (up == vp) return;
        if (size[up] > size[vp]) {
            parent[vp] = up;
            size[up] += size[vp];
        } else {
            parent[up] = vp;
            size[vp] += size[up];
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        unordered_map<string,int>m;
        DisjointSet d(n);
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string em = accounts[i][j];
                if(m.find(em)==m.end()){
                    m[em] = i;
                }else{
                    d.unionBySize(i,m[em]);
                }
            }
        }

        vector<string> list[n];
        for(const auto &it : m){
            string em = it.first; int node = it.second;
            int upNode = d.findUP(node);
            list[upNode].push_back(em);
        }

        vector<vector<string>>ans;
        for(int i=0;i<n;i++){
            if(list[i].size() == 0)continue;

            sort(list[i].begin(),list[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(const auto &em : list[i]){
                temp.push_back(em);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};