struct Node{ // making the struct node
     //each node has 26 links for every character and flag -> to mark the end for a particular word
     Node *links[26];
     bool flag = false;

     //to check if the given node contains the reference node of the character passed 
     bool containsKey(char ch){
        return (links[ch - 'a'] != NULL);
     }

     // to put the reference of the new node at the given character
    void put(char ch,Node* node){
        links[ch-'a'] = node;
    }

    // to get the reference node of the given character
    Node* get(char ch){
        return links[ch-'a'];
    }

    // to set the flag of  the current node as true -> to mark the end of the word.
    void setEnd(){
        flag = true;
    }

    // to check if the current node's flag is true -> to check the end of the word.
    bool isEnd(){
        return flag;
    }
};
class Trie {
    // initially we need the root;
private:
// creating the data member of Node* type
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        // tc -> O(len)
        Node* node = root;
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            // move to the reference trie
          node =   node -> get(word[i]);
        }
        // after inserting all the character -> set the end
        node->setEnd();
        
    }
    
    bool search(string word) {
        // You start with the root node
        // tc -> O(length of the word)
        Node* node = root;
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
                return false;
            }
            // go to the reference trie-node
            node = node -> get(word[i]);
        }
        return node->isEnd(); // to check if marked 'true'

    }
    
    bool startsWith(string prefix) {
        // tc -> O(len)
        Node* node = root;
        for(int i=0;i<prefix.length();i++){
            if(!node->containsKey(prefix[i])){
                return false;
            }
            node = node -> get(prefix[i]);
        }
        // traverse whole of the prefix -> it's exits in the trie
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