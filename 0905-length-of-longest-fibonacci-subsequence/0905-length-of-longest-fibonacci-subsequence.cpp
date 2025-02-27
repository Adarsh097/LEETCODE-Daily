class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_map<int,int>m;
        int n = arr.size();
        for(int i=0;i<n;i++){
            m[arr[i]] = i;
        }
        int maxLen = 0;
        for(int i=0;i<n;i++){
            for(int j = i+1;j<n;j++){
                int prev = arr[i];
                int curr = arr[j];
                int len = 2;
                
                while(m.find(prev+curr)!=m.end()){
                    int sum = prev + curr;
                    len++;
                    maxLen = max(maxLen,len);
                    prev = curr;
                    curr = sum;
                }
            }
        }
        return maxLen>2?maxLen:0;
    }
};