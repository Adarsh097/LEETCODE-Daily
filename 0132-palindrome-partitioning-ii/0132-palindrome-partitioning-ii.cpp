class Solution {
public:
    long long dp[2001];
    bool isPalin(string &s,int i,int j){
        
        while(i<j){
            if(s[i]!=s[j])return false;
            i++;
            j--;
        }
        return true;
    }
    long long solve(string &s,int &n,int i){
        if(i==n)return 0;

        if(dp[i]!=-1)return dp[i];

        long long minCuts = INT_MAX;
        
        for(int k=i;k<n;k++){
            
            if(isPalin(s,i,k)){
                long long cuts = 1 + solve(s,n,k+1);
                minCuts = min(minCuts,cuts);
            }
        }
        return dp[i] = minCuts;
    }
    int minCut(string s) {
        memset(dp,-1,sizeof(dp));
        int n = s.size();
        long long cuts = solve(s,n,0);
        return (int)cuts-1;
    }
};