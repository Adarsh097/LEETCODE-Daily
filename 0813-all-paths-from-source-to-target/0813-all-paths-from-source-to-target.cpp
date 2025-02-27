class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < graph.size(); i++) {
            for (auto& val : graph[i]) {
                adj[i].push_back(val);
            }
        }
        int n = graph.size();
        vector<vector<int>> ans;
        queue<vector<int>> q;
        q.push({0});
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            if (it.back() == n - 1){
                ans.push_back(it);
            }
            int val = it.back();
            vector<int> temp = it;
            for (auto& neigh : adj[val]) {
                temp.push_back(neigh);
                q.push(temp);
                temp.pop_back();
            }
        }
        return ans;
    }
};