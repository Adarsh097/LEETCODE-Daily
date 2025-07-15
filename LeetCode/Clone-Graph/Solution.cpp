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
    Node* cloneGraph(Node* node) {
        if(!node)return NULL;
        // {node,copy}
        unordered_map<Node*,Node*>m;
        Node* copy = new Node(node->val,{});
        m[node] = copy;
        queue<Node*>q;
        q.push(node);
        while(!q.empty()){
            Node* node = q.front();
            q.pop();
            for(Node* neigh : node->neighbors){
                if(m.find(neigh) == m.end()){
                    m[neigh] = new Node(neigh->val,{});
                    q.push(neigh);
                }
                m[node]->neighbors.push_back(m[neigh]);
            }
        }
        return copy;
    }
};