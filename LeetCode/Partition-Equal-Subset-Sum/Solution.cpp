class Solution {
public:
    vector<vector<int>> dp;
    bool solve(vector<int>& nums, int n, int target) {
        if (target == 0)
            return true;
        if (n == 0)
            return false;
        if (dp[n][target] != -1)
            return dp[n][target];

        bool notTake = solve(nums, n - 1, target);

        bool taken;
        if (nums[n - 1] <= target) {
            taken = solve(nums, n - 1, target - nums[n - 1]);
        }
        return dp[n][target] = notTake || taken;
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if ((sum & 1) == 1)
            return false;
        int target = sum / 2;
        int n = nums.size();
        // dp.resize(n+1,vector<int>(target+1,-1));
        // bool ans = solve(nums,n,target);
        // return ans;

        //      vector<vector<bool>> arr(n + 1, vector<bool>(target + 1,
        //      false)); for(int i=0;i<n+1;i++){
        //         arr[i][0] = true;
        //      }

        //      for(int i=1;i<n+1;i++){
        //         for(int j=1;j<target+1;j++){

        //     bool notTake = arr[i-1][j];

        //     bool taken = false;
        //     if(nums[i-1]<=j){
        //         taken =  arr[i-1][j-nums[i-1]];
        //     }
        //    arr[i][j] = notTake || taken;
        //     }
        //  }
        //  return arr[n][target];

        vector<int> prev(target + 1, false);
        prev[0] = true;
        vector<int> curr(target + 1, false);

        for (int i = 1; i < n + 1; i++) {
            curr[0] = true;
            for (int j = 1; j < target + 1; j++) {
                bool notTake = prev[j];

                bool taken = false;
                if (nums[i - 1] <= j) {
                    taken =prev[j - nums[i - 1]];
                }
                curr[j] = notTake || taken;
            }
            prev = curr;
        }
        return curr[target];
    }
};