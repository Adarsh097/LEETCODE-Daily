class Solution {
public:
    bool check(vector<int>&dist,double hour,int mid){
        double time = 0.0, i=0;
        while(i<dist.size()-1){
            time += ceil((double)dist[i]/mid);
            i++;
        }
        time += (double)dist[i]/mid;
        return time<=hour;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n =  dist.size();
       
      

        int low = 1, high = 1e7;
        int ans = high;
        while(low<=high){
            int mid = (high-low)/2 + low;
            if(check(dist,hour,mid)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        if(check(dist,hour,ans)==false)return -1;
        return ans;
    }
};