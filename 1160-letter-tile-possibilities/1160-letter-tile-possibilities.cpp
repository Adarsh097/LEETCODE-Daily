class Solution {
public:
    void solve(unordered_map<char,int>&m,int &count){
        for(auto &it : m){
            if(it.second>0){
                it.second--;
                count++;
                solve(m,count);
                it.second++;
            }
            
        }
    }
    int numTilePossibilities(string tiles) {
        unordered_map<char,int>m;
        for(auto &ch : tiles){
            m[ch]++;
        }
        int count = 0;
        solve(m,count);
        return count;
    }
};