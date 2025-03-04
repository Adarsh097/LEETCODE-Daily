class Solution {
public:
    bool solve(int num,int n){
        if(n==0)return true;
        if(num>n)return false;
        size_t temp = num * 3;

        bool take = solve(temp,n);

        bool notTake = solve(temp,n-num);

        return take || notTake;
    }
    bool checkPowersOfThree(int n) {
        bool ans = solve(1,n);
        return ans;
    }
};