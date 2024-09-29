class Solution {
public:
    vector<int>dp;
    int solve(int ind,string &s,int n){
        if(ind == n){
            // reachead at the last index -> so valid decode is found
            return 1;
        }

        if(s[ind] == '0'){
            //decode is not possible
            return 0;
        }
        if(dp[ind] !=-1)return dp[ind];

        int result = solve(ind+1,s,n);

        if(ind+1<n){
            // taking two characters
            if(s[ind]=='1' || s[ind] == '2' && s[ind+1] <= '6')
            result += solve(ind+2,s,n);
        }
        return dp[ind] = result;
    }
    int numDecodings(string s) {
        int n = s.size();

        // dp.resize(n+1,-1);
        // int ans = solve(0,s,n);
        // return ans;

        /* BOTTOM UP */

        vector<int>dp(n+1);
        dp[n] = 1;
        for(int i=n-1;i>=0;i--){
            if(s[i] == '0'){
                dp[i] = 0;
            }
            else{
            dp[i] = dp[i+1];
            if(i+1 < n){
            if(s[i]=='1' || s[i]=='2' && s[i+1] <= '6'){
                dp[i] += dp[i+2];
            }
            }
            }
        }
        return  dp[0];
        
    }
};