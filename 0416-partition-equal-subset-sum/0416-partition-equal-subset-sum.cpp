class Solution {
public:
    vector<vector<int>>dp;
    bool solve(vector<int>&nums,int ind,int &n,int target){
        if(target == 0)return true;
        if(target < 0 || ind >= n)return false;
        if(dp[ind][target]!=-1)return dp[ind][target];
        //take or not take
        bool notTaken = solve(nums,ind+1,n,target);

        bool taken;
        if(nums[ind]<=target){
            taken = solve(nums,ind+1,n,target-nums[ind]);
        }
        return dp[ind][target] = notTaken || taken;
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        cout<<sum<<endl;
        if(sum%2!=0)return false;
        int target = sum/2;
        cout<<target<<endl;
        int n = nums.size();
        dp.resize(n+1,vector<int>(target+1,-1));
        bool ans = solve(nums,0,n,target);
        return ans;
    }
};