class Solution {
public:
    vector<int>dp;
    int solve(string &s,int ind){
        if(ind==s.size())return 1;
        if(ind > s.size())return 0;
        if(dp[ind]!=-1)return dp[ind];

        int num1 = stoi(s.substr(ind,1));
        int total = 0;
        if(num1!=0){
            total += solve(s,ind+1);
        }

        int num2 = INT_MAX;
        if(s.size()-ind>=2){
            num2 = stoi(s.substr(ind,2));
            if(num2>=10 && num2<=26){
                total += solve(s,ind+2);
            }
        }
        return dp[ind] = total;
    }
    int numDecodings(string s) {
        int n  = s.size();
        dp.resize(n+1,-1);
        int ans = solve(s,0);
        return ans;
    }
};
