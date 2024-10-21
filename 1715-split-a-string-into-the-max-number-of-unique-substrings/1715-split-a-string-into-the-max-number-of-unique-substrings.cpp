class Solution {
public:
    unordered_map<string,bool>m;
    int count = 0;
    void solve(string &s,int &n, int ans, int ind){
        if(ind == n){
            count = max(count,ans);
            return;
        }

        string temp = "";
        for(int i = ind;i<n;i++){
            temp += s[i];
            if(m.find(temp) == m.end()){
                //string is unique
                m[temp] = true;
                solve(s,n,ans+1,i+1);
                m.erase(temp);
            
            }
        }
    }
    int maxUniqueSplit(string s) {
        int n = s.size();
        int ans  = 0;
        solve(s,n,ans,0);
        return count;
    }
};