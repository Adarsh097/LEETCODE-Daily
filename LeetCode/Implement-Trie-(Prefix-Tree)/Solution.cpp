/*
the time complexity for insertion, search, and prefix search is O(L), and the space complexity is O(N), 
where L is the length of words or prefixes and N is the total number of characters in all words.
*/
class Trie {
public:
    struct trieNode{
        trieNode* children[26];
        bool isEndOfWord;
    };

    trieNode* getNode(){
        trieNode* newNode = new trieNode();
        newNode->isEndOfWord = false;

        for(int i=0;i<26;i++){
            newNode->children[i] = nullptr;
        }
        return newNode;
    }
    
    /* INITIALISING THE ROOT OF THE TRIE */
    trieNode* root;
    Trie() {
        root = getNode();
    }
    
    void insert(string word) {
        /* MAKING THE TEMP -> TO TRAVERSE TRIE */
        trieNode* temp = root;

        for(char &ch: word){
            int idx = ch - 'a';
            if(!temp->children[idx]){
                temp->children[idx] = getNode();
            }
            temp = temp->children[idx];
        }
        /* now at the end of the word */
        temp -> isEndOfWord = true;
    }
    
    bool search(string word) {
        trieNode* temp = root;
        for(char &ch : word){
            int idx = ch - 'a';
            if(!temp->children[idx]){
                return false;
            }
            temp = temp->children[idx];
        }
        return temp->isEndOfWord;
    }
    
    bool startsWith(string prefix) {
        trieNode* temp = root;
        for(char &ch : prefix){
            int idx = ch - 'a';
            if(!temp->children[idx]){
                return false;
            }
            temp = temp->children[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */