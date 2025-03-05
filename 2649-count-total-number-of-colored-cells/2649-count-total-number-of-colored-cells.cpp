class Solution {
public:
    long long coloredCells(long long n) {
        if(n==1)return 1;
        return 1 + (2 * (n-1)*(n));
        
    }
};