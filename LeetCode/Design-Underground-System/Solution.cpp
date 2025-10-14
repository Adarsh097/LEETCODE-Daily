class UndergroundSystem {
public:
    unordered_map<int,pair<string,int>>m;
    unordered_map<string,unordered_map<string,pair<int,double>>>m2;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        m[id] = {stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string startStation = m[id].first;
        int s = m[id].second;
        int time = t-s;
        auto &p = m2[startStation][stationName];
        p.first+=time;
        p.second++;
        m2[startStation][stationName] = p;
        return;
    }
    
    double getAverageTime(string startStation, string endStation) {
        auto &p =    m2[startStation][endStation];
        return p.first/p.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */