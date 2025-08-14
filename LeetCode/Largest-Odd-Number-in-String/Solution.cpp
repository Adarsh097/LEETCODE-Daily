class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        string ans = "";
        int ind = -1;
        for(int i=n-1;i>=0;i--){
            int val = num[i]-'0';
            if((val&1)==1){
                ind = i;
                break;
            }
        }
        
        return num.substr(0,ind+1);
    }
};