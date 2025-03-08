class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int ans = k,cnt = 0,e = 0, s = 0, n = blocks.size(),white = 0;
        while(e<k){
            if(blocks[e]=='W')white++;
            e++;
        }
        ans = min(ans,white);
        while(e<n){
            if(blocks[s]=='W')white--;
            s++;
            if(blocks[e]=='W')white++;
            e++;
            ans = min(ans,white);
        }
        return ans;
    }
};