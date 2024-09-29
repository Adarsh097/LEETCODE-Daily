class Solution {
public:
    bool checkPalindrome(string &s, int i,int j){
        while(i<=j){
            if(s[i]==s[j]){
                i++;
                j--;
            }else{
                return false;
            }
        }
        return true;
    }
    string longestPalindrome(string s) {
        int maxLength =  INT_MIN;
        int sp = 0;

        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                if(checkPalindrome(s,i,j)){
                    if(j-i+1>maxLength){
                        maxLength = j-i+1;
                        sp = i;
                    }
                }
            }
        }
        return s.substr(sp,maxLength);
    }
};