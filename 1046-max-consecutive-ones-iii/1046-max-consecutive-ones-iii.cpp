class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int head = -1, tail = 0, len = 0,cnt = 0;
        int n = nums.size();
        while(tail < n){
            while(head + 1 < n && (nums[head+1]==1 || cnt < k)){
                head++;
                if(nums[head]==0)cnt++;
            }

            len = max(len,head-tail+1);


            if(tail > head){
                tail++;
                head = tail - 1;

            }else{
                if(nums[tail]==0)cnt--;
                tail++;
            }

        }
        return len;
    }
};