class Solution {
public:
    int mySqrt(int x) {
       
        int s = 0, e = x;
        int ans = -1;
        while(s<=e){
            int mid = (e-s)/2 + s;
            if(pow(mid,2)==x)return mid;
            else if(pow(mid,2)<x){
                ans = mid;
                s = mid+1;
            }else{
                e = mid-1;
            }
        }
        return ans;
    }
};