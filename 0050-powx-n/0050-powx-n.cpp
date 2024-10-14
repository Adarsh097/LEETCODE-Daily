class Solution {
public:
    double solve(double x,long n){
        if(n==0)return 1.0;
        if(n<0)return solve(1/x,-n);
        if((n&1)!=1) return solve(x*x,n/2);
        else return  x*solve(x*x,(n-1)/2);
    }
    double myPow(double x, int n) {
        return solve(x,(long)n);
    }
};
// range -> 2^(-31) to 2^(31)-1
// x^(-n), where n == INT_MIN; => (1/x)^n will result in overflow -> take long for the n

//binary exponentiation ->
/*
    x^n => (x*x)^(n/2) ,if n is even
    x^n => x*((x*x)^(n/2)) ,if n is odd
 */