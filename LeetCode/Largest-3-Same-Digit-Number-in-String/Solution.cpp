class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        if(n<3)return "";
        int i=0,j=2;
        string ans = "";
        while(j<n){
            if(num[i]==num[i+1] && num[j]==num[j-1]){
                if(ans.empty() || ans[2]-'0' < num[j]-'0')
                ans =  num.substr(i,3);
                
            }
            i++;j++;
        }
        return ans;
    }
};