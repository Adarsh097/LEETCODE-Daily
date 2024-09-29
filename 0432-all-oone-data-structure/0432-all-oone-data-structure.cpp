class AllOne {
unordered_map<string,int>m;
set<pair<int,string>>s;
public:
    AllOne() {
        
    }
    
    void inc(string key) {
        int old_count = m[key];
        if(s.count({old_count,key})){
            s.erase({old_count,key});
        }
        m[key]++;
        s.insert({m[key],key});
    }
    
    void dec(string key) {
        int old_count = m[key];
        m[key]--;
        if(m[key] == 0){
            m.erase(key);
            s.erase({old_count,key});
        }else{
            s.erase({old_count,key});
            s.insert({m[key],key});
        }
    }
    
    string getMaxKey() {
        if(s.empty())return "";
        auto it = s.end();
        it--;
        return it->second;
    }
    
    string getMinKey() {
        if(s.empty())return "";
        auto it = s.begin();
        return it->second;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */