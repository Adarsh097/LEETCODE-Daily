1class Solution {
2public:
3    vector<int> findErrorNums(vector<int>& nums) {
4        int n = nums.size();
5        vector<int>temp(n,0);
6        int dup = -1, miss = -1;
7        for(int i=0;i<n;i++){
8            int ind = nums[i]-1;
9            if(temp[ind]==nums[i])dup = nums[i];
10            else{
11                temp[ind] = nums[i];
12            }
13        }
14        for(int i=0;i<n;i++){
15            if(temp[i]==0)miss = i+1;
16        }
17        return {dup,miss};
18    }
19};