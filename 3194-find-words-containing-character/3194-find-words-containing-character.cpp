class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int>ans;
        for(int i=0;i<words.size();i++){
            for(int ch=0;ch<words[i].size();ch++){
                if(words[i][ch] == x){
                    ans.push_back(i);
                    break;
                };
            }
        }
        return ans;
    }
};