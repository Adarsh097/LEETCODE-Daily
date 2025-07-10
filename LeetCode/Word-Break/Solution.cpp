class Solution {
public:
    unordered_map<string,bool>m;
    vector<int>dp;
    bool solve(string &s, int ind, int &n){
        if(ind == n){
            // string todte-todte end mein agaye
            return true;
        }

        // if complete string is preseint in dict
        if(m.find(s) != m.end())return true;

        if(dp[ind] !=-1)return dp[ind];

        for(int l=1;l<=n;l++){
            string temp = s.substr(ind,l);
            if(m.find(temp)!=m.end()  && solve(s,ind+l,n)){
                return dp[ind] = true;
            }
        }
        return dp[ind] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto &str : wordDict){
            m[str] = true;
        }
        int n = s.size();
        dp.resize(n+1,-1);
        bool ans = solve(s,0,n);
        return ans;
    }
};