class Solution {
public:
    int reverseDegree(string s) {
        int reverseDeg = 0;
        for(int i=0;i<s.size();i++){
            reverseDeg += ((i+1)*(26 - (s[i] - 'a')));
        }
        return reverseDeg;
    }
};