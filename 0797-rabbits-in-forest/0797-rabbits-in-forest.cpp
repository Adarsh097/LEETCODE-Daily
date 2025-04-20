class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int>m;
        for(auto &val : answers){
            m[val]++;
        }
        int ans = 0;
        for(auto &it : m){
            int x = it.first;
            int groupSize = x + 1;
            int count = it.second;

            int groups = ceil((double)count/groupSize);
            ans += groups * groupSize;
        }
        
        return ans;

    }
};