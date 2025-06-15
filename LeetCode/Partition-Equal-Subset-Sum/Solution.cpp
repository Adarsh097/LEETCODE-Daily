class Solution {
public:
    vector<vector<int>>dp;
    bool solve(vector<int>&nums,int n,int target){
        if(target == 0)return true;
        if(n==0)return false;
        if(dp[n][target]!=-1)return dp[n][target];

        bool notTake = solve(nums,n-1,target);

        bool taken;
        if(nums[n-1]<=target){
            taken = solve(nums,n-1,target-nums[n-1]);
        }
        return dp[n][target] = notTake || taken;
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if((sum&1)==1)return false;
        int target = sum/2;
        int n = nums.size();
        dp.resize(n+1,vector<int>(target+1,-1));
        bool ans = solve(nums,n,target);
        return ans;
    }
};