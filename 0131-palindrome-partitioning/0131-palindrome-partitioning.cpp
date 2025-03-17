class Solution {
public:
    bool checkPalindrome(string &str){
        int s = 0, e = str.size()-1;
        while(s<=e){
            if(str[s]!=str[e])return false;
            s++;e--;
        }
        return true;
    }
    vector<vector<string>>ans;
    vector<string>temp;
    void solve(string &s,int ind){
        if(ind==s.size()){
            ans.push_back(temp);
            return;
        }

        string str = "";
        for(int i=ind;i<s.size();i++){
            str += s[i];
            if(checkPalindrome(str)){
                temp.push_back(str);
                solve(s,i+1);
                temp.pop_back();
            }
        }
        return;
    }
    vector<vector<string>> partition(string s) {
        solve(s,0);
        return ans;
    }
};