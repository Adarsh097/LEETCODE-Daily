class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(),wordList.end());

        queue<pair<string,int>>q;
        q.push({beginWord,1});
        st.erase(beginWord);// mark the word

        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            if(word == endWord)return steps;

            //check for scenarios
            for(int i=0;i<word.length();i++){
                char original = word[i];
                for(char ch = 'a'; ch<='z';ch++){
                    word[i] = ch;
                    if(st.find(word) != st.end()){
                        st.erase(word);
                        q.push({word,steps+1});
                    }
                }
                word[i] = original;
            }
        }
        return 0;
    }
};