class Solution {
public:
    vector<int> dp;
    int solve(vector<int>& nums, int n) {
        if (n <= 0)
            return 0;
        if (dp[n] != -1)
            return dp[n];
        int opt1 = nums[n - 1] + solve(nums, n - 2);
        int opt2 = solve(nums, n - 1);
        return dp[n] = max(opt1, opt2);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        // dp.resize(n+1,-1);
        // int ans = solve(nums,n);
        // return ans;

        /* BOTTOM UP */
        // vector<int> arr(n + 1, 0);
        // arr[1] = nums[0];
        // for (int i = 2; i < n + 1; i++) {
        //     int opt1 = nums[i - 1] + arr[i-2];
        //     int opt2 = arr[i-1];
        //     arr[i] = max(opt1, opt2);
        // }
        // return arr[n];


        /* SPACE OPTIMISED */
        int arr1 = 0;
        int arr2 = nums[0];
        for(int i=2;i<n+1;i++){
            int opt1 = nums[i-1] + arr1;
            int opt2 = arr2;
            int curr = max(opt1,opt2);
            arr1 = arr2;
            arr2 = curr;
        }
        return arr2;
    }
};