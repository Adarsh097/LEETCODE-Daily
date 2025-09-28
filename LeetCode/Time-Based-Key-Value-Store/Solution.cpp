class TimeMap {
public:
    unordered_map<string,map<int,string>>m;
    string check(int time, string &key){
        string ans = "";
        auto &mp = m[key];
        auto it = mp.upper_bound(time);
        if(it==mp.begin())return "";
        it--;
        

        return it->second;

    }
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key][timestamp]=value;
    }
    
    string get(string key, int timestamp) {
        string ans = check(timestamp,key);
        return ans;

    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */