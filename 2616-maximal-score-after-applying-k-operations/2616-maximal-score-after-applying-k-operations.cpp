class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans = 0;
        priority_queue<int>pq;
        for(auto &val : nums){
            pq.push(val);
        }
        while(k--){
            int val = pq.top();
            pq.pop();
            ans += val;
            val= ceil((double)(val)/3);
            pq.push(val);
        }
        return ans;
    }
};