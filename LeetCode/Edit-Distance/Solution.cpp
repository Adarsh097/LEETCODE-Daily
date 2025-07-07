class Solution {
public:
    vector<vector<int>>dp;
    int solve(string &word1,string &word2,int m,int n){
        if(m==0)return n;
        if(n==0)return m;
        if(dp[m][n]!=-1)return dp[m][n];

        if(word1[m-1] == word2[n-1]){
            return dp[m][n] = solve(word1,word2,m-1,n-1);
        }else{
            int opt1 = 1 + solve(word1,word2,m-1,n);
             int opt2 = 1 + solve(word1,word2,m,n-1);
              int opt3 = 1 + solve(word1,word2,m-1,n-1);
              return dp[m][n] = min({opt1,opt2,opt3});
        }
    }
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        dp.resize(m+1,vector<int>(n+1,-1));
        int ans = solve(word1,word2,m,n);
        return ans;
    }
};