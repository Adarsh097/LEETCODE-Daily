class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;

        for(int i=0;i<nums.size();i++){
            if(k>0){
                pq.push(nums[i]);
                k--;
            }else{
                if(nums[i] > pq.top()){
                    pq.push(nums[i]);
                    pq.pop();
                }
            }
        }
        return pq.top();
    }
};