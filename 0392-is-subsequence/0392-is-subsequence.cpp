class Solution {
public:
    bool isSubsequence(string s, string t) {
        int ind1 = 0, ind2 = 0;
        while(ind1<s.size() && ind2<t.size()){
            if(s[ind1] == t[ind2]){
                ind1++;
                ind2++;
            }else{
                ind2++;
            }
        }
        return ind1 == s.size();
    }
};