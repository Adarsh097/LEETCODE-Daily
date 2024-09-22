class MedianFinder {
private:
    priority_queue<int>maxLeft;
    priority_queue<int,vector<int>,greater<int>>minRight;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxLeft.empty() || num < maxLeft.top()){
            maxLeft.push(num);
        }else{
            minRight.push(num);
        }

        //balance
        // keeping size of leftHeap atmost one greater than the right
        // but size of right heap shouldn't be greater than the size of the left heap
        if(abs((int)maxLeft.size() - (int)minRight.size())>1){
            minRight.push(maxLeft.top());
            maxLeft.pop();
        }else if(minRight.size() > maxLeft.size()){
            maxLeft.push(minRight.top());
            minRight.pop();
        }
    }
    
    double findMedian() {
        if(maxLeft.size() != minRight.size()){
            return maxLeft.top();
        }else{
            double ans = (maxLeft.top() + minRight.top())/2.0;
            return ans
            ;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */