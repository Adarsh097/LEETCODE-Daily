class Solution {
public:
    int maximumSwap(int num) {
        int ans = num;
        string str = to_string(num);
        int n = str.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(str[j]-'0' > str[i]-'0'){
                    swap(str[j],str[i]);
                    ans = max(ans,stoi(str));
                    swap(str[j],str[i]);
                }
            }
        }
        return ans;
    }
};