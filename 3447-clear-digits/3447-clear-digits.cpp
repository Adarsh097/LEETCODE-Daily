class Solution {
public:
    string clearDigits(string s) {
        int cnt = 0;
       
        
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]>='0' && s[i]<='9')cnt++;
            else if(s[i]>='a' && s[i]<='z'){
                if(cnt>0){
                    s[i] = ' ';
                    cnt--;
                }
            }
        }
        string ans = "";
        for(auto &ch : s){
            if(ch>='a'&& ch<='z'){
                ans += ch;
            }
        }
        return ans;
        
        
    }
};