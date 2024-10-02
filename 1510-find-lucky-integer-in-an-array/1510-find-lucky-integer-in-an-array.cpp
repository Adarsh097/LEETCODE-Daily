class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int>m;
        for(auto &val : arr){
            m[val]++;
        }
        int maxi = INT_MIN;
        for(auto &it : m){
            if(it.first == it.second){
                maxi = max(maxi,it.first);
            }
        }
        if(maxi ==INT_MIN)
        return -1;
        return maxi;
    }
};