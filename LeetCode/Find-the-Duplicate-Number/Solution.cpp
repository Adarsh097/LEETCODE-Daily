class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // mark the indices as negative equal to number to find the ans -> T: O(n) and S: O(1) -> but modifying the array
        
        // slow and fast pointer -> T: O(n) and S:O(1) -> optimised algorithm

        int slow = nums[0];
        int fast = nums[0];

        // find the common point
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);


        // find the point where the cycle starts
        slow  = nums[0];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;



    }
};