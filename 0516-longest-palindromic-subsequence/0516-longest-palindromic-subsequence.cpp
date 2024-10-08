class Solution {
public:
    vector<vector<int>>dp;
    int lcs(string &str1,string &str2, int ind1,int ind2){
        if(ind1==0 || ind2==0)return 0;
        if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
        int ans = 0;
        if(str1[ind1-1] == str2[ind2-1]){
            ans = 1 + lcs(str1,str2,ind1-1,ind2-1);
        }else{
            ans = max({lcs(str1,str2,ind1-1,ind2),lcs(str1,str2,ind1,ind2-1)});
        }
        return dp[ind1][ind2] = ans;
    }
    int longestPalindromeSubseq(string s) {
        string str1 = s;
        string str2 = s;
        reverse(str2.begin(),str2.end());
        int n = s.size();
        dp.resize(n+1,vector<int>(n+1,-1));
        int ans = lcs(str1,str2,n,n);
        return ans;
    }
};