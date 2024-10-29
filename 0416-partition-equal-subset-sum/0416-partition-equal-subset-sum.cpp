class Solution {
public:
    vector<vector<int>>dp;
    bool solveM(vector<int>& nums,int n,int target){
        if(target == 0)return true;
        if(target<0 || n == 0)return false;
        if(dp[n][target] != -1)return dp[n][target];
        // take
        int opt1 = solveM(nums,n-1,target - nums[n-1]);

        // not take 
        int opt2 = solveM(nums,n-1,target);

        return dp[n][target] = opt1 || opt2;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        if((sum & 1)==1)return false;
        int target  = sum/2;
        dp.resize(n+1,vector<int>(target+1,-1));
        bool ans = solveM(nums,n,target);
        return ans;
    }
};