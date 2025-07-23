class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        vector<int>arr(distance.begin(),distance.end());
        int sum = accumulate(distance.begin(),distance.end(),0);
       
        int n = distance.size();
        int ind1 = start;
        int dist1 = 0, dist2 = 0;
        
        while(ind1 !=destination){
            dist1 += distance[ind1];
            ind1 = (ind1+1)%n;
        }
        return min(dist1,sum-dist1);
    }
};