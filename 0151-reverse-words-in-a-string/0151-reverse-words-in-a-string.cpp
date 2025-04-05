class Solution {
public:
    string reverseWords(string s) {
        string ans = "", temp = "";
        s  = " " + s;
        for(int i = s.size()-1;i>=0;i--){
            if(s[i]!=' '){
                temp = s[i] + temp;
            }else{
               if(temp=="")continue;
                ans = ans + temp + " ";
                temp = "";
            }
        }
        ans.pop_back();
   
        return ans;
    }
};