class Solution {
public:
    unordered_map<string,bool>m;
    unordered_map<int,bool>dp;
    
    bool solve(string s,int ind){
        if(ind == s.size())return true;
        if(dp.find(ind)!=dp.end())return dp[ind];

        string str = "";
        for(int i = ind;i<s.size();i++){
            str += s[i];
            if(m.find(str)!=m.end()){
                if(solve(s,i+1))return dp[ind] =  true;
            }
        }
        return dp[ind] =  false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto &word : wordDict){
            m[word] = true;
        }
        bool ans = solve(s,0);
        return ans;
    }
};