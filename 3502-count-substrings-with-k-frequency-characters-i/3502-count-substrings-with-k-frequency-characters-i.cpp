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
            while(m[ch]>=k){
                ans += (n-j);
                m[s[i]]--;
                i++;
            }
            j++;
        }
        return ans;
    }
};