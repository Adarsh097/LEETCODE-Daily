class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long m = n;
        if(n<0){
            m = -m;
        }
        while(m){
            if(m&1){
                ans = ans * x;
                m = m-1;
            }else{
                x = x*x;
                m = m/2;
            }
        }
        if(n<0)return 1.0/(double)ans;
        return ans;
    }
};