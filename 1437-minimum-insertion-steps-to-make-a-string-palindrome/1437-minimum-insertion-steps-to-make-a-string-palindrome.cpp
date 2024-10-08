class Solution {
public:
    /* 
        To convert this into the palindrome -> 
            1. find the lps of the string then-> length of the string - length(lps)
            2. the characters that don't participate in making the lps will be added/inserted to make entire string as the palindrome.
     */

    //CACHING
    vector<vector<int>>dp;

    int lcs(string &str1,string &str2,int ind1,int ind2){
        if(ind1==0 || ind2==0){
            //length of the lcs will be zero
            return 0;
        }
        if(dp[ind1][ind2] != -1)return dp[ind1][ind2];
        int ans = 0;
        if(str1[ind1-1] == str2[ind2-1]){
            //character has matched -> include the character in the lcs
            ans = 1 + lcs(str1,str2,ind1-1,ind2-1);
        }else{
            // check for the two scenarios
            ans = max({lcs(str1,str2,ind1-1,ind2),lcs(str1,str2,ind1,ind2-1)});
        }
        return dp[ind1][ind2] = ans;
    }
    int minInsertions(string s) {
        int n = s.size();
        dp.resize(n+1,vector<int>(n+1,-1));
        string str1 = s;
        reverse(str1.begin(),str1.end());
        int lps = lcs(s,str1,n,n);

        return n - lps;
    }
};