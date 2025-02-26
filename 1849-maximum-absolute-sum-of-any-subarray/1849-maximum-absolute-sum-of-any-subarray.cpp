class Solution {
public:
   
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int maxSub = 0,preSum1=0;
        int minSub = 0,preSum2 = 0;
        for(int i=0;i<n;i++){
            preSum1+= nums[i];
            preSum2+= nums[i];
            maxSub = max(maxSub,preSum1);
            if(preSum1<0)preSum1 = 0;
            minSub = min(minSub,preSum2);
            if(preSum2>0)preSum2 = 0;
        }
        return max(abs(minSub),maxSub);
    }
};