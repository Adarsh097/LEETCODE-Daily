class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int fuel = startFuel, ind = 0, stops = 0;
        int n = stations.size();
        priority_queue<int>pq;
        while(fuel < target){
            while(ind<n && fuel >= stations[ind][0]){
                pq.push(stations[ind][1]);
                ind++;
            }


            // can't reach any fuel station
            if(pq.empty())return -1;

            fuel += pq.top();
            pq.pop();
            stops++;


        }
        return stops;
    }
};