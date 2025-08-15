class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)return false;
        return log10(n)/log10(2) == (int)(log10(n)/log10(2));
    }
};