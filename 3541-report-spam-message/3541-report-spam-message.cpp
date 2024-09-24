class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_map<string,bool>m;
        for(auto &word : bannedWords){
            m[word] = true;
        }
        int count = 0;
        for(auto &word : message){
            if(m.find(word) != m.end()){
                count++;
                m[word] = false;
            }
        }
        return count >= 2;
    }
};