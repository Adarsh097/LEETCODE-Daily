class Solution {
public:
    bool check(vector<int>&jobs,int ind,vector<int>&w,int &mid){
        if(ind==jobs.size()){
            return true;
        }

        int val = jobs[ind];
        for(int i=0;i<w.size();i++){
            if(w[i]+val <= mid){
                w[i] += val;
                if(check(jobs,ind+1,w,mid))return true;
                w[i] -= val;
            }
            if(w[i]==0)return false;
        }
        return false;
    }
    int minimumTimeRequired(vector<int>& jobs, int k) {
        
        sort(jobs.rbegin(), jobs.rend());
        int low = jobs[0],
        high = accumulate(jobs.begin(),jobs.end(),0);
        int ans = -1;
        while(low<=high){
            int mid = low +((high-low)>>1);
            vector<int>workers(k,0);
            if(check(jobs,0,workers,mid)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};