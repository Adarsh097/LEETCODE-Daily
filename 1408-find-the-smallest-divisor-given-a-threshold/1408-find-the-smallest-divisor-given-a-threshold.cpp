class Solution {
public:
    bool check(vector<int>&arr,int thres,int div){
        int sum = 0;
        for(int i=0;i<arr.size();i++){
            sum += (arr[i]%div==0)?arr[i]/div:(arr[i]/div)+1;
        }
        return sum <= thres;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1, high = *max_element(nums.begin(),nums.end());

        int ans = high;
        while(low<=high){
            int mid = (high-low)/2 + low;
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