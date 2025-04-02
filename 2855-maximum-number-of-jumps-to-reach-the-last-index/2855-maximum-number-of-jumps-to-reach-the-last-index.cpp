class Solution {
public:
    vector<int>dp;
    int solve(vector<int>&nums,int &target,int ind){
        if(ind==nums.size()-1)return 0;

        if(dp[ind]!=-1)return dp[ind];

        int ans = INT_MIN;
        for(int i=ind+1;i<nums.size();i++){
            if(abs(nums[i]-nums[ind])<=target){
                int temp = 1 + solve(nums,target,i);
                ans = max(ans,temp);
            }
        }
        return dp[ind] = ans;

        

    }
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        dp.resize(n+1,-1);
        int ans = solve(nums,target,0);
        return ans<0?-1:ans;
    }
};