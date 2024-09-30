class CustomStack {
    vector<int>v;
    int size;
    int currSize;
public:
    CustomStack(int maxSize) {
        size = maxSize;
        currSize = 0;
    }
    
    void push(int x) {
        if(currSize < size){
            v.push_back(x);
            currSize++;
        }
    }
    
    int pop() {
        if(currSize == 0)return -1;
        int ans = v.back();
        v.pop_back();
        currSize--;
        return ans;

    }
    
    void increment(int k, int val) {
        for(int i=0;i<v.size();i++){
            if(k>0){
                v[i] += val;
                k--;
            }
        }
        return;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */