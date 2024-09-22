class MedianFinder {
private:
    priority_queue<int> leftMaxHeap;
    priority_queue<int,vector<int>,greater<int>>rightMinHeap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(leftMaxHeap.empty() || num < leftMaxHeap.top()){
            leftMaxHeap.push(num);
        }else{
            rightMinHeap.push(num);
        }

        //balance the size
        if(abs((int)leftMaxHeap.size() - (int)rightMinHeap.size())>1){
            rightMinHeap.push(leftMaxHeap.top());
            leftMaxHeap.pop();
        }else if(rightMinHeap.size() > leftMaxHeap.size()){
            leftMaxHeap.push(rightMinHeap.top());
            rightMinHeap.pop();
        }
    }
    
    double findMedian() {
        if(leftMaxHeap.size() == rightMinHeap.size()){
            double ans = (leftMaxHeap.top() + rightMinHeap.top())/2.0;
            return ans;
        }else{
            return leftMaxHeap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */