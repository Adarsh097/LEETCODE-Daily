class Solution {
public:
    //  unordered_map<int,int>m;
    // int dominantElement(vector<int>&nums){

    //     for(auto &val : nums)m[val]++;
    //     int ele = -1, freq = 0;
    //     for(auto &it : m){
    //         if(it.second > freq){
    //             ele = it.first;
    //             freq = it.second;
    //         }
    //     }
    //     return (freq>nums.size()/2)?ele:-1;
    // }

    pair<int, int> dominantElement(vector<int>& nums) {
        int ele = 0, freq = 0;
        for (auto& val : nums) {
            if (val == ele) {
                freq++;
            } else {
                if (freq == 0) {
                    ele = val;
                    freq = 1;
                } else {
                    freq--;
                }
            }
        }
        int cnt = 0;
        for(auto &val : nums){
            if(val==ele)cnt++;
        }

        return {ele,cnt};
    }

    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        // int domEle = dominantElement(nums);
        // if(domEle==-1)return -1;
        // int freq = m[domEle];

        // SPACE OPTIMIZATION
        auto [domEle, freq] = dominantElement(nums);

        int cnt1 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == domEle)
                cnt1++;
            cout << cnt1 << endl;
            int cnt2 = freq - cnt1;
            if (cnt1 > (i + 1) / 2 && cnt2 > (n - i - 1) / 2)
                return i;
        }
        return -1;
    }
};