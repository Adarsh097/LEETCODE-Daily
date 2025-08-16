class Solution {
public:
    int maximum69Number (int num) {
        int temp = num;
        int pos = -1;
        int ind = 0;
        while(temp){
            int digit = temp%10;
            if(digit==6){
                pos = ind;
            }
            temp/=10;
            ind++;
        }
        int val = 3*pow(10,pos);
        return (pos>=0)?num+val:num;
    }
};