class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int n = s.size();
        int ans = 0;
        int i = 0, j = 0;
        unordered_map<char,int>m;
        while(j<n){
            char  ch = s[j];
            m[ch]++;
            if(m[ch]>=k){
                ans += (n-j);
            }
            while(m[ch]>=k){
                m[s[i]]--;
                if(m[ch]>=k){
                    ans += (n-j);
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};