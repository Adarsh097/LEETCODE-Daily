class Solution {
public:
    int n;
    // changing parameters is target only
    vector<int>dp;
    int solve(vector<int>& nums, int target){
        if(target == 0){
            // target is reached -> one possible way
            return 1;
        }
        if(target < 0){
            // target not possible;
            return 0;
        }
        if(dp[target] != -1)return dp[target];

        int ans = 0;
        for(int i=0;i<n;i++){
            ans += solve(nums,target-nums[i]);
        }
        return dp[target] = ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        n = nums.size();
        dp.resize(target+1,-1);
        int ans = solve(nums,target);
        return ans;
    }
};