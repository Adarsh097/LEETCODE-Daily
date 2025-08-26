class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>s;
        s.insert(wordList.begin(),wordList.end());
        s.erase(beginWord);
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            string word = it.first; int cnt = it.second;
            if(word == endWord)return cnt;

            for(int i=0;i<word.size();i++){
                char ch = word[i];
                for(char l='a';l<='z';l++){
                    word[i] = l;
                    if(s.find(word)!=s.end()){
                        s.erase(word);
                        q.push({word,cnt+1});
                    }
                }
                word[i] = ch;
            }
        }
        return 0;
    }
};