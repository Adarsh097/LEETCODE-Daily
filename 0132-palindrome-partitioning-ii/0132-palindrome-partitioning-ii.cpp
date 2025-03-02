class Solution {
public:
    int n;
    vector<int>dp;
    bool isPalin(string &s, int i,int j){
        while(i<j){
            if(s[i]!=s[j])return false;
            else{
                i++;j--;
            }
        }
        return true;
    }
    int solve(string &s,int ind){
        if(ind>=n)return 0;
        if(dp[ind]!=-1)return dp[ind];

        int mini = INT_MAX;
        for(int k=ind;k<n;k++){
            if(isPalin(s,ind,k)){
                int temp = 1 + solve(s,k+1);
                mini  = min(mini,temp);
            }
        }
        return dp[ind] = mini;
    }
    int minCut(string s) {
        n = s.size();
        dp.resize(n+1,-1);
        int ans = solve(s,0);
        return ans-1;
    }
};