class Solution {
public:
    bool check(vector<int>&brr,int m,int k,int days){
        int count = 0;
        for(int i=0;i<brr.size();i++){
            if(brr[i]<=days){
                count++;
                if(count==k){
                    m--;
                    count=0;
                }
                if(m==0)return true;
            }else{
                count = 0;
            }
        }
        return m<=0;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
      int low = *min_element(bloomDay.begin(),bloomDay.end()),   
      high = *max_element(bloomDay.begin(),bloomDay.end()),
      n = bloomDay.size();

      if(n<(long long)m*k)return -1;
      int ans = high;
      while(low<=high){
        int mid = ((high-low)>>2) + low;
        if(check(bloomDay,m,k,mid)){
            ans = mid;
            high = mid-1;
        }else{
            low = mid+1;
        }

      }
      return ans;
    }
};