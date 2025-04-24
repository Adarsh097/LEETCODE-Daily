class Solution {
public:
    int solve(int cnt, vector<int>&nums){
        unordered_map<int,int>m;
        int i=0,j=0;
        int ans = 0;
        while(i<nums.size()){
            m[nums[i]]++;
            while(m.size()>cnt){
                m[nums[j]]--;
                if(m[nums[j]]==0)m.erase(nums[j]);
                j++;
            }
            ans += (i-j+1);
            i++;
        }
        return ans;
    }
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int>s;
        for(auto &val : nums){
            s.insert(val);
        }
        int cnt = s.size();
        return solve(cnt,nums) - solve(cnt-1,nums);
    }
};