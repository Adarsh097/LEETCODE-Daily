class Solution {
public:
    bool check(long long &mid,long long &cars,vector<int>&arr){
        long long count = 0;
        for(int i=0;i<arr.size();i++){
            count += (long long) sqrtl(mid/arr[i]);
            if(count>=cars)return true;
        }
        return false;
    }
    long long repairCars(vector<int>& ranks, long long cars) {
        long long low = 1,
        high = (long long)*max_element(ranks.begin(),ranks.end())*cars*cars;
        long long ans = high;
        while(low<=high){
            long long mid = (high-low)/2 + low;
            if(check(mid,cars,ranks)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};