class Solution {
public:
    bool check(vector<int>&arr,int th,int mid){
        double sum = 0.0;
        for(int i=0;i<arr.size();i++){
            sum += ceil((double)arr[i]/mid);
        }
        return int(sum)<=th;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1, high = *max_element(nums.begin(),nums.end());
        int ans = high;
        while(low<=high){
            int mid = low + ((high-low)>>1);
            if(check(nums,threshold,mid)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};