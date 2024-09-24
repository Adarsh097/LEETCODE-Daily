class Solution {
public:
    vector<vector<int>>dp;
    int solve(string &text1,string &text2, int ind1, int ind2){
        if(ind1 == 0 || ind2 == 0){
            return 0;
        }
        if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
        int ans = 0;
        if(text1[ind1-1] == text2[ind2-1]){
            ans = 1 + solve(text1,text2,ind1-1,ind2-1);
        }else{
            int opt1 = solve(text1,text2,ind1-1,ind2);
            int opt2 = solve(text1,text2,ind1,ind2-1);
            ans = max({opt1,opt2});
        }
        return dp[ind1][ind2] = ans;
    }
    int longestCommonSubsequence(string text1, string text2) {
        int ind1 = text1.size();
        int ind2 = text2.size();
        dp.resize(ind1+1,vector<int>(ind2+1,-1));
        int ans = solve(text1,text2,ind1,ind2);
        return ans;
    }
};