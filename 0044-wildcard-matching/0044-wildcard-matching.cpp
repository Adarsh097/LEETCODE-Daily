class Solution {
public: 
    vector<vector<int>>dp;
    bool allStars(string &p, int ind){
        for(int i=0;i<ind;i++){
            if(p[i] != '*'){
                return false;
            }
        }
        return true;
    }
    bool solve(string &s, string &p, int ind1, int ind2,vector<vector<int>>&dp){
         if(ind1 == 0 && ind2 == 0){
            return true;
        }
        if(ind1 == 0 && ind2 != 0){
            return allStars(p,ind2);
        }
         if(ind2 == 0 && ind1 != 0){
            return false;
        }
        if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
        bool ans = false;
        if(s[ind1-1] == p[ind2-1] || p[ind2-1]=='?'){
            // character are equal
            ans = solve(s,p,ind1-1,ind2-1,dp);
        }else if(p[ind2-1]=='*'){
            ans = solve(s,p,ind1-1,ind2,dp) || solve(s,p,ind1,ind2-1,dp);
        }
        return dp[ind1][ind2] = ans;

    }
    bool isMatch(string s, string p) {
        int  ind1 = s.size();
        int ind2 = p.size();
        dp.resize(ind1+1,vector<int>(ind2+1,-1));
        bool ans = solve(s,p,ind1,ind2,dp);
        return ans;
    }
};