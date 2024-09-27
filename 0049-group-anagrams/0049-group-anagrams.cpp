class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>m;
        int n = strs.size();

        for(int i=0;i<n;i++){
            string str = strs[i];
            sort(str.begin(),str.end());
            m[str].push_back(strs[i]);
        }
        vector<vector<string>>ans;
        for(auto &it:m){
            ans.push_back(it.second);
        }
        return ans;
    }
};