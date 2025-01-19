class Solution {
public:
    typedef pair<int,int> P;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        unordered_map<int,vector<pair<int,int>>> adjlist;
    //    /pahla int pair ka v store karegea dusara weight karega 
        for(int i=0;i<times.size();i++){
            vector<int> temp=times[i];
            int u=temp[0];
            int v=temp[1];
            int weight=temp[2];
            adjlist[u].push_back({v,weight});
        }
        // ab minheap bana lete hai
        priority_queue<P,vector<P>,greater<P>> minheap;
        minheap.push({0,k}); // 0 time le kar k node par jaunga
        int ans=0;
        vector<int> dist(n+1,INT_MAX);
        dist[k]=0;
        while(!minheap.empty()){
            auto [dir,node]=minheap.top();minheap.pop();
            if(dir > dist[node]) continue;
            for(auto v:adjlist[node]){
                int nextnode=v.first;
                int edgeweight=v.second;
                if(dir+edgeweight < dist[nextnode]){
                    dist[nextnode]=dir+edgeweight;
                    minheap.push({dist[nextnode],nextnode});
                }
            }
        }
        // ab check kar lete hai kya koi node visit nahi ho paya hai to
        int maxi=*max_element(dist.begin()+1,dist.end());
        return maxi==INT_MAX?-1:maxi;
        return ans;
        
    }
};