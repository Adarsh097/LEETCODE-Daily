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
        dp.resize(n+1,-1);
        int ans = solve(0,s,n);
        return ans;
    }
};