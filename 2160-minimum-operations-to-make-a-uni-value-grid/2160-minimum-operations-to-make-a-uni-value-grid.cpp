class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        // to get minOperation -> try to make all the values equal to medina value
        // median -> floor(length/2)
        // (a,b) can be equal iff -> a%key == b%key
        vector<int>arr;
        for(auto &it: grid){
            for(auto &val : it){
                arr.push_back(val);
            }
        }
        sort(arr.begin(),arr.end());
        int n = arr.size();
        int median = arr[n/2];
        int operations = 0;
        for(auto &val : arr){
            if(median%x != val%x)return -1;
            operations += abs(median-val)/x;
        }
        return operations;
    }
};