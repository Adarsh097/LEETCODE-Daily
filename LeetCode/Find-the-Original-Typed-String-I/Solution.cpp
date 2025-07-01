class Solution {
public:
    int possibleStringCount(string word) {
        int cnt = 0;
        word += '#';
        unordered_map<char,int>m;
        int flag = true;
        for(int i=0;i<word.size()-1;i++){
            if(word[i]!=word[i+1]){
                if(flag){
                    cnt += m[word[i]]+1;
                    flag = false;
                    cout<<m[word[i]]<<endl;
                    m[word[i]] = 0;
                }else{
                    cnt += m[word[i]];
                     m[word[i]] = 0;
                      cout<<m[word[i]]<<endl;
                }
            }else{
                m[word[i]]++;
            }   
        }
        return cnt;
    }
};