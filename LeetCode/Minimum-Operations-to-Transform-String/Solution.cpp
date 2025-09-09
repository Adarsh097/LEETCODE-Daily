class Solution {
public:
    int minOperations(string s) {
       sort(s.begin(),s.end());
       for(auto &ch : s){
        if(ch!='a'){
            return 26 - (int(ch) - int('a'));
        }
       }
       return 0;
    }
};