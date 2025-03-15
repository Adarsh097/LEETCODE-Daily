class Solution {
public:
    vector<vector<int>>dp;
    int solve(string&text1, string &text2, int ind1,int ind2){
        if(ind1==0 || ind2==0)return 0;
        if(dp[ind1][ind2] != -1)return dp[ind1][ind2];

        if(text1[ind1-1] == text2[ind2-1]){
            return dp[ind1][ind2] = 1 + solve(text1,text2,ind1-1,ind2-1);
        }else{
            return dp[ind1][ind2] = max(solve(text1,text2,ind1-1,ind2),solve(text1,text2,ind1,ind2-1));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        // dp.resize(m+1,vector<int>(n+1,-1));
        // int lcs = solve(text1,text2,m,n);

        // return lcs;


        /* TABULATION */

    //     dp.resize(m+1,vector<int>(n+1,0));

    //     for(int i=1;i<m+1;i++){
    //         for(int j=1;j<n+1;j++){
    //             if(text1[i-1] == text2[j-1]){
    //          dp[i][j] = 1 + dp[i-1][j-1];
    //     }else{
    //          dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
    //         }
    //     }
       
    // }
    //  return dp[m][n];


    /* SPACE OPTIMISED */
    vector<int>prev(n+1,0);
    vector<int>curr(n+1,0);
           for(int i=1;i<m+1;i++){
            
            for(int j=1;j<n+1;j++){
                if(text1[i-1] == text2[j-1]){
             curr[j] = 1 + prev[j-1];
        }else{
             curr[j] = max(prev[j],curr[j-1]);
            }
        }
        prev = curr;
       
    }
    return prev[n];

    }
};