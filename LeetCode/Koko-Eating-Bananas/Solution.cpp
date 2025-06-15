class Solution {
public:
    bool check(int &x,vector<int>& piles, int h){
      int i=0;
      while(i<piles.size()){
        if(piles[i]<=x){
            h--;
        }else{
            h -= piles[i]/x;
            if(piles[i]%x != 0)h--;
        }
        i++;
      }
      return h>=0;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1,
        high = *max_element(piles.begin(),piles.end());
        int ans = high;
        while(low<=high){
            int mid = ((high-low)>>1) + low;

            if(check(mid,piles,h)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};