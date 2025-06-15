class Solution {
public:
    vector<vector<int>> dp;
    bool solve(vector<int>& nums, int target, int ind) {
        if (target == 0)
            return true;
        if (ind == 0)
            return false;
        if (dp[ind][target] != -1)
            return dp[ind][target];
        bool notTaken = solve(nums, target, ind - 1);

        bool taken;
        if (nums[ind - 1] <= target) {
            taken = solve(nums, target - nums[ind - 1], ind - 1);
        }
        return dp[ind][target] = taken || notTaken;
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if ((sum & 1) == 1)
            return false;
        int target = sum / 2;
        int n = nums.size();
        // dp.resize(n+1,vector<int>(target+1,-1));
        // bool ans = solve(nums,target,n);
        // return ans;

        /* TABULATION */
        // vector<vector<bool>> arr(n + 1, vector<bool>(target + 1, false));
        // for (int i = 0; i < n + 1; i++) {
        //     arr[i][0] = true;
        // }

        // for (int row = 1; row < n + 1; row++) {
        //     for (int col = 1; col < target + 1; col++) {
        //         bool notTaken = arr[row-1][col];

        //         bool taken = false;
        //         if (nums[row - 1] <= col) {
        //             taken = arr[row-1][col-nums[row-1]];
        //         }
        //          arr[row][col] = taken || notTaken;
        //     }
        // }
        // return arr[n][target];

        /* SO */
        vector<int> prev(target + 1, false);
        prev[0] = true;
        vector<int> curr(target + 1, false);
        for (int row = 1; row < n + 1; row++) {
            for (int col = 1; col < target + 1; col++) {
                bool notTaken =  prev[col];

                bool taken = false;
                if (nums[row - 1] <= col) {
                    taken = prev[col-nums[row-1]];
                }
                curr[col] = taken || notTaken;
            }
            prev = curr;
        }
        return prev[target];
    }
};