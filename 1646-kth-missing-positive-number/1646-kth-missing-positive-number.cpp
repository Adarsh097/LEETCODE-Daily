class Solution {
public:
    int findKthPositive(std::vector<int>& arr, int k) {
        int low = 1, high = arr.back() + k; 
        
        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            int ub = std::lower_bound(arr.begin(), arr.end(), mid) - arr.begin();
            int missingCount = mid - (ub + 1);  

            if (missingCount >= k) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return low-1;
    }
};