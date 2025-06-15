class Solution {
public:
    bool check1(int val, int target) { return val >= target; }
    bool check2(int val, int target) { return val > target; }
    int firstOcurr(vector<int>& nums, int target) {
        int ans = -1, low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = ((high - low) >> 1) + low;
            if (check1(nums[mid], target)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
    int lastOcurr(vector<int>& nums, int target) {
        int ans = nums.size(), low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = ((high - low) >> 1) + low;
            if (check2(nums[mid], target)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int fo = firstOcurr(nums, target);
        if (fo == -1 || nums[fo] != target)
            return {-1, -1};
        int lo = lastOcurr(nums, target);
        return {fo, lo-1};
    }
};