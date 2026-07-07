class Solution {
    public long sumAndMultiply(int n) {
        long ans = 0;
        long i = 0, sum = 0;
        while(n>0){
            int digit = n%10;
            n/=10;
            if(digit !=0){
                sum+=digit;
                ans = (long)Math.pow(10,i)*digit + ans;
                i++;
            }
        }
        return sum * ans;
    }
}