/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*,Node*>m;
    void solve(Node* node){
        Node* newNode  = new Node(node->val);
        m[node] = newNode;
        for(auto &neigh : node->neighbors){
            if(m.find(neigh)==m.end()){
                 solve(neigh);
            }
            newNode->neighbors.push_back(m[neigh]);

        }
        return;
    }
    
    Node* cloneGraph(Node* node) {
        if(!node)return NULL;
        solve(node);
        return m[node];
    }
};