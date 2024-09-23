class MedianFinder {
public:
    priority_queue<int>maxL;
    priority_queue<int,vector<int>,greater<int>>minR;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxL.empty() || maxL.top() > num){
            maxL.push(num);
        }else{
            minR.push(num);
        }

        //balance
        if(abs((int)maxL.size() - (int)minR.size())>1){
            minR.push(maxL.top());
            maxL.pop();
        }
        else if(minR.size() > maxL.size()){
            maxL.push(minR.top());
            minR.pop();
        }
    }
    
    double findMedian() {
        if(maxL.size() != minR.size()){
            return maxL.top();
        }else{
            double ans = (maxL.top() + minR.top())/2.0;
            return ans;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */