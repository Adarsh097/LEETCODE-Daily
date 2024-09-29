class FrequencyTracker {
    unordered_map<int,int>m;
    unordered_map<int,int>freq;
public:
    FrequencyTracker() {
        
    }
    
    void add(int number) {
        int currFreq = m[number];

        if(currFreq > 0){
            freq[currFreq]--;

            if(freq[currFreq] == 0){
                freq.erase(currFreq);
            }

        }
        m[number]++;
        freq[m[number]]++;
    }
    
    void deleteOne(int number) {
        if(m.find(number)!=m.end() && m[number]>0){
            int currFreq = m[number];

            freq[currFreq]--;
            if(freq[currFreq] == 0){
                freq.erase(currFreq);
            }

            m[number]--;
            if(m[number] == 0){
                m.erase(number);
            }else{
                freq[m[number]]++;
            }
        }
    }
    
    bool hasFrequency(int frequency) {
        return freq.find(frequency) != freq.end();
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */