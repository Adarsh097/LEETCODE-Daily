class Solution {
public:
    bool check(int num,int val,int sum){
        int temp1 = num;
        int temp2 = sum;
        int i=0;
        while(temp1>0){
            int digit = temp1%10;
            temp1/=10;
            temp2 = digit*pow(10,i) + temp2;
            i++;
            if(temp2 + temp1 == val)return true;
            else if(check(temp1,val,temp2))return true;
        }
        return false;
    }
    int punishmentNumber(int n) {
        int totalSum = 0;
        for(int i=1;i<=n;i++){
            int num = i*i;
            if(check(num,i,0)){
                totalSum += num;
            }
        }
        return totalSum;
    }
};