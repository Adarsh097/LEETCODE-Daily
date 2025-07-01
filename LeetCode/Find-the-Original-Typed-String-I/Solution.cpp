class Solution {
public:
    int possibleStringCount(string word) {
        
      int ans  = 0;
        int count = 1;
        for(int i=0;i<word.size()-1;i++){
            if(word[i] == word[i+1]){
                count++;
            }else{
                if(count >= 2){
                    ans += count - 1;
                }
                count = 1;
            }
        }
        ans += count;
        ans + 1;
        return ans;
    }
};