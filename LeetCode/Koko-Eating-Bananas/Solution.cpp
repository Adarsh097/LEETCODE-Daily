class Solution {
public:
    bool check(vector<int>&piles,int h,int &count){
        int i =0;
        while(i<piles.size()){
            if(piles[i]<=count){
                h--;
            }else{
                h-=(piles[i]/count);
                if(piles[i]%count!=0)h--;
            }
            i++;
        }
        return h>=0;
           
        
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1, e = *max_element(piles.begin(),piles.end());

        int ans = -1;
        while(s<=e){
            int mid = (e-s)/2 + s;
            if(check(piles,h,mid)){
                ans = mid;
                e = mid-1;
            }else{
                s = mid+1;
            }
        }
        return ans;
    }
};