#define ll long long
class Solution {
public:
    long long minimumSteps(string str) {
        int s = 0, e = str.size()-1;
            ll ans = 0;
        while(s<e){
            if(str[s]=='0')s++;
            else if(str[e]=='1')e--;
            else{
                ans += (e-s);
                e--;s++;
            }
        }
        return ans;
    }
};