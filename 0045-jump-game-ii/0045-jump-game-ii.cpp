class Solution {
public:
    vector<int>dp;
    int solve(vector<int>&arr,int ind,int &n){
        if(ind>=n)return 1e9;
        if(ind==n-1){
            return 0;
        }
        if(dp[ind]!=-1)return dp[ind];
       
        int jumps = n;
        for(int i=1;i<=arr[ind];i++){
            int temp = 1 + solve(arr,ind+i,n);
            jumps = min(jumps,temp);
        }
        return dp[ind] = jumps;

    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n+1,-1);
        int ans = solve(nums,0,n);
        return ans;
    }
};