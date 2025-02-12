class Solution {
public:
    bool check(vector<int>&arr,int days,int cap){
        days-=1;
        int temp = cap;
        for(int i=0;i<arr.size();i++){
            int val = arr[i];
            if(val <= temp){
                temp -= val;
            }else{
                if(days==0)return false;
                days--;
                temp = cap;
                if(temp < val)return false;
                temp -= val;
            }
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
         int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);

        int ans = high;
        while(low<=high){
            int mid = (high-low)/2 + low;
            if(check(weights,days,mid)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};