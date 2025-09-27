class Node{
public:
    string data;
    Node* next;
    Node* prev;
    
    Node(string data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};
class BrowserHistory {
public:
    Node* head;
    Node* temp;
    BrowserHistory(string homepage) {
        head = new Node(homepage);
        temp = head;
    }
    
    void visit(string url) {
        Node* newNode = new Node(url);
        Node* toDel = temp->next;
        temp->next = NULL;
        if(toDel)delete(toDel);
        temp->next = newNode;
        newNode->prev = temp;
        temp = newNode;
        return;
    }
    
    string back(int steps) {
        while(steps){
            if(!temp->prev)break;
            temp = temp->prev;
            steps--;
        }
        return temp->data;
    }
    
    string forward(int steps) {
        while(steps){
            if(!temp->next)break;
            temp = temp->next;
            steps--;
        }
        return temp->data;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */