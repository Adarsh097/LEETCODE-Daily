class Solution {
public:
    int atmostKsum(vector<int>&nums,int k){
        int count = 0, l = 0, r = 0, n = nums.size();
        long  sum=0;
        while(r<n){
            if(nums[r]==1)sum++;
            while(l<=r && sum>k){
                if(nums[l]==1){
                    sum--;
                }
                l++;
            }
            if(r>=l)
            count += (r-l+1);
            r++;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmostKsum(nums,goal) - atmostKsum(nums,goal-1);
    }
};