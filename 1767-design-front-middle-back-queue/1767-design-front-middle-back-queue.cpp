class FrontMiddleBackQueue {
public:
    deque<int>d1,d2;
    int n1,n2;
    FrontMiddleBackQueue() {
        n1 = 0;
        n2 = 0;
    }
    
    void pushFront(int val) {
        d1.push_front(val);
        if(n1 == n2){
            // equal so, there is not problem in inserting one element in d1
            n1++;
        }else{
            // d1>d2 already
            d2.push_front(d1.back());
            d1.pop_back();
            n2++;
        }
    }
    
    void pushMiddle(int val) {
        if(n1 == n2){
            // equal so, there is not problem in inserting one element in d1
                 d1.push_back(val);
            n1++;
        }else{
            // d1>d2 already
            d2.push_front(d1.back());
            d1.pop_back();
             d1.push_back(val);
            n2++;
        }
    }
    
    void pushBack(int val) {
           d2.push_back(val);
        if(n2<n1){
            n2++;
        }else{
            d1.push_back(d2.front());
            d2.pop_front();
            n1++;
        }
    }
    
    int popFront() {
        if(n1 + n2 == 0)return -1;
        int ans = d1.front();
        d1.pop_front();
        n1--;
        if(n1<n2){
            d1.push_back(d2.front());
            d2.pop_front();
            n1++;
            n2--;
        }
        return ans;
    }
    
    int popMiddle() {
        if(n1 + n2 == 0)return -1;
        int ans = d1.back();
        d1.pop_back();
        n1--;
        if(n1<n2){
            d1.push_back(d2.front());
            d2.pop_front();
            n1++;
            n2--;
        }
        return ans;

    }
    
    int popBack() {
        if(n1 + n2 == 0)return -1;
        if(n2==0){
            int ans = d1.back();
            n1--;
            d1.pop_back();
            return ans;
        }
        int ans = d2.back();
        d2.pop_back();
        n2--;
        if(n2+1 < n1){
            d2.push_front(d1.back());
            d1.pop_back();
            n1--;
            n2++;
        }
        return ans;

    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */