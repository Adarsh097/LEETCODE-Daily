class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        vector<int>arr(distance.begin(),distance.end());
        for(auto val : distance){
            arr.push_back(val);
        }
        int n = distance.size();
        int ind1 = start;
        int ind2 = destination;
        int dist1 = 0, dist2 = 0;
        
        while(ind1 !=destination){
            dist1 += distance[ind1];
            ind1++;
            ind1%=n;
        }
      
        cout<<dist1<<endl;
        while(ind2 !=start){
            dist2 += distance[ind2];
            ind2++;
            ind2 %=n;
        }
        cout<<dist2<<endl;
        return min(dist1,dist2);

        
    }
};