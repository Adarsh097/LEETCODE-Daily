class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int minDiff = INT_MAX;
        for(int i=0;i<n-1;i++){
            minDiff = min(minDiff,nums[i+1]-nums[i]);
        }
        return minDiff;
    }
};