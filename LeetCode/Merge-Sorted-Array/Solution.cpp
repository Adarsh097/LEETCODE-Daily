class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>v;
        int ind1 = 0, ind2 = 0;
        while(ind1<m && ind2<n){
            if(nums1[ind1] < nums2[ind2]){
                v.push_back(nums1[ind1++]);
            }else{
                v.push_back(nums2[ind2++]);
            }
        }
        while(ind1<m){
            v.push_back(nums1[ind1++]);
        }
        while(ind2<n){
            v.push_back(nums2[ind2++]);
        }
        nums1.clear();
        for(auto &val:v){
            nums1.push_back(val);
        }
        return;
    }
};