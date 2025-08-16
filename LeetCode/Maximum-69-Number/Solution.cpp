class Solution {
public:
    int maximum69Number (int num) {
        int pos = -1;
        int temp = 0;
        int n = num;
        while(n>0){
            int digit = n%10;
            n/=10;
            if(digit==6){
                pos = temp;
            }
            temp++;
        }
        int toAdd = 3*pow(10,pos);
        return (pos>=0)?toAdd+num:num;
    }
};