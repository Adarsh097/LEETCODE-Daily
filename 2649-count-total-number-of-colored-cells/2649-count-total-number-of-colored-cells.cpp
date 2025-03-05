class Solution {
public:
    long long coloredCells(long long n) {
        return (n==1)?1 : 1 + (2 * (n-1)*(n));
        
    }
};