class LFUCache {
public:
    int cap;
    int size;
    unordered_map<int,list<vector<int>>::iterator>mp;
    map<int,list<vector<int>>>freq; // freq-> {key,val,count}
    LFUCache(int capacity) {
        cap = capacity;
        size = 0;
    }

    void makeFreqUsed(int key){
        auto &vec = *(mp[key]);
        int val = vec[1], f = vec[2];
        freq[f].erase(mp[key]);
        if(freq[f].empty())
            freq.erase(f);
        f++;
        freq[f].push_front({key,val,f});
        mp[key] = freq[f].begin();
        return;

    }
    
    int get(int key) {
        if(mp.find(key)==mp.end())return -1;
        auto vec = *(mp[key]);
        int val = vec[1];

        makeFreqUsed(key);
        return val;
    }
    
    void put(int key, int value) {
        if(cap == 0)return;
        if(mp.find(key)!=mp.end()){
            auto &vec = *(mp[key]);
            vec[1] = value;
            makeFreqUsed(key);

        }else if(size < cap){
            size++;
            freq[1].push_front({key,value,1});
            mp[key] = freq[1].begin();
        }else{
            auto &list = freq.begin()->second;
            auto key_del = list.back()[0];
            list.pop_back();
            if(list.empty()){
                freq.erase(freq.begin()->first);
            }
            freq[1].push_front({key,value,1});
            mp.erase(key_del);
            mp[key] = freq[1].begin();
        }

    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */