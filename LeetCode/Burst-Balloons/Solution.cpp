class Solution {
public:
    int dp[303][303];
    int solve(vector<int>&nums,int i,int j){
        if(i > j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];

        int maxCoins = 0;
        for(int k=i;k<=j;k++){
            int coins = nums[i-1]*nums[k]*nums[j+1];
            int rem = solve(nums,i,k-1)  + solve(nums,k+1,j);
            maxCoins = max(maxCoins,rem+coins);
        }
        return dp[i][j] =  maxCoins;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        memset(dp,-1,sizeof(dp));
        nums.insert(nums.begin(),1);
        int ans = solve(nums,1,n);
        return ans;
    }
};