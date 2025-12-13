1class Solution {
2public:
3    int findMaxConsecutiveOnes(vector<int>& nums) {
4        int prev = -1, curr = -1;
5        int ans = 0,n=nums.size();
6        for(int i=0;i<nums.size();i++){
7            if(nums[i]==0)curr = i;
8            ans = max(ans,curr-prev-1);
9            prev = curr;
10
11        }
12        ans = max(ans,n-prev-1);
13        return ans;
14    }
15};