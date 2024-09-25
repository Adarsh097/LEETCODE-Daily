class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return false;

        string str = to_string(x);
        bool ans = true;
        int i=0;
        int j=str.length()-1;
        while(i<=j){
            if(str[i] != str[j]){
                ans = false;
                break;
            }
            i++;j--;
        }
        return ans;
    }
};