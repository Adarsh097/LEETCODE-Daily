class Node{
    public:
    int data;
    Node* prev;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};
class MyLinkedList {
public:
    Node* head;
    Node* tail;
    MyLinkedList() {
        head = new Node(-1);
        tail = new Node(-1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int index) {
        Node* temp = head;
        while(index--){
            if(!temp)return -1;
            temp = temp->next;
        }
        if(!temp->next || temp->next->data==-1)return -1;
        return temp->next->data;
        
    }
    
    void addAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head->next;
        newNode->prev = head;
        newNode->next->prev = newNode;
        head->next = newNode;
        return;
    }
    
    void addAtTail(int val) {
        Node* newNode = new Node(val);
        newNode->next = tail;
        newNode->prev = tail->prev;
        newNode->prev->next = newNode;
        tail->prev = newNode;
    }
    
    void addAtIndex(int index, int val) {
          Node* temp = head;
        while(index--){
            if(!temp)break;
            temp = temp->next;
        }
        if(!temp || !temp->next)return;
        Node* newNode = new Node(val);
        newNode->next=temp->next;
        newNode->prev = temp;
        newNode->next->prev = newNode;
        temp->next = newNode;
        return;
    
    }
    
    void deleteAtIndex(int index) {
        Node* temp = head;
        while(index--){
            if(!temp)break;
            temp = temp->next;
        }
        if(!temp || !temp->next || temp->next->data==-1)return;
        Node* delNode = temp->next;
        temp->next = delNode->next;
        delNode->next->prev = temp;
        delete(delNode);
        return;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */