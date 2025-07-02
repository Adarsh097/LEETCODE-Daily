class Solution {
public:
    int possibleStringCount(string word) {
        int cnt = 0;
        word += '#';
        // unordered_map<char,int>m;
        int total = 1;
        int flag = true;
        for(int i=0;i<word.size()-1;i++){
            if(word[i]!=word[i+1]){
                if(flag){
                    cnt += total;
                    flag = false;
                   total = 1;
                }else{
                    cnt += total-1;
                    total= 1;
                }
            }else{
                // m[word[i]]++;
                total++;
            }   
        }
        return cnt;
    }
};