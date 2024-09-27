class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int ans = 0;
        int l = 0, r= 0;
        int n = s.size();
        unordered_map<char,int>m;
        while(r<n){
            if(m.find(s[r])==m.end()){
                //character is not present
                m[s[r]]++;
                ans = max(ans,r-l+1);
            }else{
                // character is already there
                while(m[s[r]]>0){
                    m[s[l]]--;
                    l++;
                }
                m[s[r]]++;
                ans = max(ans,r-l+1);
            }
            r++;
        }
        return ans;
    }
};