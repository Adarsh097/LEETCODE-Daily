class Solution {
public:
    int minOperations(string s) {
        int ans = 0;
        for(auto &ch : s){
            ans = max(ans,(26 - (int(ch)-int('a')))%26);
        }
        return ans;
    }
};