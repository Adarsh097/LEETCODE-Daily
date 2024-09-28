class MyCircularQueue {
private:
    vector<int>q;
    int front;
    int currSize;
    int size;
    int rear;
public:
    MyCircularQueue(int k) {
        q = vector<int>(k,0);
        front = 0;
        rear = 0;
        currSize = 0;
        size = k;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        rear = (rear + 1)%size;
        q[rear] = value;
        currSize++;
        if(currSize == 1) front = rear;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        front = (front + 1)%size;
        currSize--;
        if(currSize == 0){
            front = 0;
            rear = 0;
        }
        
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return q[front];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return q[rear];
    }
    
    bool isEmpty() {
        return currSize == 0;
    }
    
    bool isFull() {
        return currSize == size;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */