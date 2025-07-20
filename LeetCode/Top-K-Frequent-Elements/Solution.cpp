class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>cnt;
        vector<vector<int>> freq(nums.size()+1);

        for(const auto &val :nums){
            cnt[val]++;
        }

        for(const auto& it : cnt){
            freq[it.second].push_back(it.first);
        }

        vector<int>ans;
        for(int i=freq.size()-1;i>0;i--){
            for(auto &val : freq[i]){
                ans.push_back(val);
                if(ans.size()==k)return ans;
            }
        }
        return ans;
    }
};
