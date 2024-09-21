class Solution {
public:
 /* 
    1. store the count of each element in the map.

    2. MAX Heap -> if you use the max-heap to store the elements then, you will have to store all the element in the heap to find out the ans ->T(NlogN) and S(N) -> for the heap

    3. MIN Heap -> if you use min-heap, store the first k element in the heap -> pop the elements only when elements after the kth-element has frequency greater than the top element of the heap.
    
    4. Finally, store the ans.
  */
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        for(auto val : nums) m[val]++;

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        for(auto it : m){
            if(k>0){
                pq.push({it.second,it.first});
                k--;
            }else{
                if(it.second > pq.top().first){
                    pq.pop();
                    pq.push({it.second,it.first});
                }
            }
        }
        vector<int>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;

    }
};