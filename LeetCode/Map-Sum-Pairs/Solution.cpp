class MapSum {
    unordered_map<string,int>m;
public:
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        m[key] = val;
    }
    
    int sum(string prefix) {
        int totalSum = 0;
        for(auto &it : m){
            string str = it.first;
            if(str.find(prefix)==0){
                totalSum += it.second;
            }
        }
        return totalSum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */