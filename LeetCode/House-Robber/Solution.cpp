class Solution {
public:
   
    int rob(vector<int>& nums) {
        int n=nums.size()-1;
        //creating the vector array
        vector<int>dp(n+1,0);
        //for zero house case
        dp[0]=nums[0];

        for(int i=1;i<=n;i++){
        int temp=0;
        if(i-2>=0){
            temp=dp[i-2];
        }
        //include
        int include=nums[i] + temp;
        //exclude
        int exclude= 0 + dp[i-1];
        //storing the ans
        dp[i] = max(include,exclude);
        }
        return dp[n];
    }
};