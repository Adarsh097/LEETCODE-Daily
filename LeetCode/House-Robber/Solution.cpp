class Solution {
public:
    int solve(vector<int>& nums, int index, int& n) {
        if (index >= n) {
            // out of bound -> no house to rob
            return 0;
        }
        // include the house
        int opt1 = nums[index] + solve(nums, index + 2, n);
        int opt2 = 0 + solve(nums, index + 1, n);
        int ans = max(opt1, opt2);
        return ans;
    }
    int solveMemo(vector<int>& nums, int index, int& n, vector<int>& dp) {
        if (index >= n) {
            // out of bound -> no house to rob
            return 0;
        }
        // if already calc
        if (dp[index] != -1) {
            return dp[index];
        }
        // include the house
        int opt1 = nums[index] + solveMemo(nums, index + 2, n, dp);
        int opt2 = 0 + solveMemo(nums, index + 1, n, dp);
        dp[index] = max(opt1, opt2);
        return dp[index];
    }

    int solveTab(vector<int>& nums, int index, int& n) {
        // 1. create the vector
        vector<int> dp(n + 1, -1);

        // 2. fill the base cases
        dp[n] = 0; // out of bound house
        if (n == 0)
            return 0;

        dp[n - 1] = nums[n - 1];

        // opposite iteration as that of the top down
        for (int index = n - 2; index >= 0; index--) {
            int opt1 = nums[index] + dp[index + 2];
            int opt2 = 0 + dp[index + 1];
            dp[index] = max(opt1, opt2);
        }
        // last se start pe arahe hai ans build karte - karte
        return dp[0];
    }
    int solveOpt(vector<int>& nums){
         // 1. create the vector
        // vector<int> dp(n + 1, -1);

        // 2. fill the base cases
        int n = nums.size();
        // last box
        int prev = nums[n-1];
        // out of bound
        int next = 0;

        int curr;
        // opposite iteration as that of the top down
        for (int index = n - 2; index >= 0; index--) {
            int opt1 = nums[index] + next;
            int opt2 = 0 + prev;
            curr = max(opt1, opt2);
            //updating the variables
            next = prev;
            prev = curr;
        }
        // last se start pe arahe hai ans build karte - karte
        return prev;
    }
    int rob(vector<int>& nums) {
        // RECURSION
        int n = nums.size();
        int index = 0;
        // int ans = solve(nums,index,n);

        // // TOP DOWN
        // vector<int>dp(n+1,-1);
        // int ans = solveMemo(nums,index,n,dp);

        // BOTTOM UP
        // int ans = solveTab(nums, index, n);


        //space optimised
        int ans = solveOpt(nums);

        return ans;
    }
};