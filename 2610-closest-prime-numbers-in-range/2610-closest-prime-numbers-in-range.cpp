class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        // sieve of Eranthoses for efficiently calculating the primes
        vector<bool>arr(right+1,true);
        arr[0]  = arr[1] = false;
        for(int i=2;i*i<=right;i++){
            if(arr[i]){
                for(int j=i*i;j<=right;j+=i){
                    arr[j] = false;
                }
            }
        }
        vector<int>temp;
        for(int i = left;i<=right;i++){
            if(arr[i])temp.push_back(i);
        }
        if(temp.size()<=1)return {-1,-1};
        int a = -1,b = -1, diff = right-left+1;
        for(int i=1;i<temp.size();i++){
            if(temp[i]-temp[i-1]<diff){
                a = temp[i-1];
                b = temp[i];
                diff = temp[i]-temp[i-1];
            }
        }
        return {a,b};


    }
};