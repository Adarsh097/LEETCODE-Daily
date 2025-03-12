class Solution {
public:
    
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int lb = lower_bound(nums.begin(),nums.end(),0) - nums.begin();
        int up = upper_bound(nums.begin(),nums.end(),0) - nums.begin();
        if(lb==n)return n;
        int neg = lb, pos = n-up;
        return (neg>pos)?neg:pos;

    }
};