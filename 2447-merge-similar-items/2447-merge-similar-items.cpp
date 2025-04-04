class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        vector<vector<int>> ans;
        int i = 0, j = 0;
        int m = nums1.size(), n = nums2.size();
        while (i < m && j < n) {
            int id1 = nums1[i][0], id2 = nums2[j][0];
            if (id1 == id2) {
                ans.push_back({id1, nums1[i][1] + nums2[j][1]});
                i++;j++;
            } else if (id1 > id2) {
                ans.push_back({id2, nums2[j][1]});
                j++;
            } else {
                ans.push_back({id1, nums1[i][1]});
                i++;
            }
        }
        while (i < m) {
            ans.push_back({nums1[i][0], nums1[i][1]});
            i++;
        }
        while (j < n) {
            ans.push_back({nums2[j][0], nums2[j][1]});
            j++;
        }
    
        return ans;
    }
};