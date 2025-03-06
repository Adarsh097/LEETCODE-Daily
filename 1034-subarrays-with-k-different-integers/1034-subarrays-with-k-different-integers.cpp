class Solution {
public:
    int solve(vector<int>&nums,int k){
        int n = nums.size(), s = 0, e = 0, cnt = 0;
        unordered_map<int,int>m;
        while(e<n){
            m[nums[e]]++;
            while(m.size()>k){
                m[nums[s]]--;
                if(m[nums[s]]==0)m.erase(nums[s]);
                s++;
            }
            cnt += (e-s+1);
            e++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums,k)-solve(nums,k-1);
    }
};