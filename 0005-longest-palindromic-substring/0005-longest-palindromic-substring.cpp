class Solution {
public:
    bool isPalindrome(string &str){
        int i=0;
        int n=str.size()-1;
        while(i<=n){
            if(str[i] != str[n])return false;
            i++;n--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int ans = INT_MIN;
        int sp = 0;
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                int len = j-i+1;
                string word = s.substr(i,len);
                if(isPalindrome(word) && len > ans){
                    ans = len;
                    sp = i;
                }
            }
        }
        return s.substr(sp,ans);
    }
};