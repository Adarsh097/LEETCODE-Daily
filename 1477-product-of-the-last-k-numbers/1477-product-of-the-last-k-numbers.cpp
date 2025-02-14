class ProductOfNumbers {
public:
    vector<int>v;
    int curr;
    ProductOfNumbers() {
        curr = 1;
    }
    
    void add(int num) {
       if(num==0){
        v.clear();
        curr = 1;
       }else{
        curr *= num;
        v.push_back(curr);
       }
    }
    
    int getProduct(int k) {
        int n = v.size();
        if(n<k)return 0;
        else if(n==k)return v[n-1];
        else return v[n-1]/v[n-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */