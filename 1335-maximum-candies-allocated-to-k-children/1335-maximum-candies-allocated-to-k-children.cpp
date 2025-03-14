class Solution {
public:
    bool check(vector<int>& candies,long long &k,long long &mid){
        long long count = 0;
        int i=0;
        while(i<candies.size()){
            int candycount = candies[i];
            count += candycount/mid;
            i++;
        }
        return count>=k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        long long  low = 1, high = *max_element(candies.begin(),candies.end());
        long long  ans = 0;
        while(low<=high){
            long long  mid = (high-low)/2 + low;
            if(check(candies,k,mid)){
                ans = mid;
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return (int)ans;
    }
};