class Solution {
public:
    bool check(long long mid,vector<int>&time,long long &trips){
        long long count = 0;
        for(int i=0;i<time.size();i++){
            count += mid/time[i];
        }
        return count >= trips;
    }
    long long minimumTime(vector<int>& time, long long totalTrips) {
        long long low = 1, high = 1e14;
        long long ans = high;
        while(low<=high){
            long long mid = (high-low)/2 + low;
            if(check(mid,time,totalTrips)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};