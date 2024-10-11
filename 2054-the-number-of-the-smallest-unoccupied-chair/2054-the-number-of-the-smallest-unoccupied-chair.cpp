class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int ans = -1;
        int targetStart = times[targetFriend][0];
        int n = times.size();
        vector<int>chairs(n,0);
        sort(times.begin(),times.end());
       
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<n;i++){
            int s = times[i][0];
            int e = times[i][1];
            while(!pq.empty()){
                if(s >= pq.top().first){
                    int chairInd = pq.top().second;
                    chairs[chairInd] = 0;
                    pq.pop();
                }else{
                    break;
                }
            }
            // Find the valid chair index from the chair array
            int ind = -1;
            for(int i=0;i<n;i++){
                if(chairs[i]==0){
                    ind = i;
                    break;
                }
            }
            // alot the chair
            chairs[ind] = 1;
            if(s == targetStart){
                ans = ind;
            }
            //push in the pq
            pq.push({e,ind});
        }
        return ans;
    }
};