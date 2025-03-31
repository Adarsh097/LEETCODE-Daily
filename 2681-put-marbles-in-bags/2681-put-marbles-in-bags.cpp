class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        vector<long long>arr;
        for(int i=0;i<n-1;i++){
            arr.push_back(weights[i]+weights[i+1]);
        }
        sort(arr.begin(),arr.end());
        long long temp1 = 0, temp2 = 0, j = arr.size()-1 ;
       for(int i=0;i<k-1;i++){
        temp1 += (long long)arr[i];
        temp2 += (long long)arr[j-i];
       }
       return temp2 - temp1;
    }
};