class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
          std::ios_base::sync_with_stdio(false);  // Disable synchronization with C I/O
          std::cin.tie(nullptr);                  // Untie cin from cout
        int n = skill.size();
        int teams = n/2;
        long long sum = accumulate(skill.begin(),skill.end(),0);
        if(sum%teams!=0)return -1;
        int target = sum/teams;
        sort(skill.begin(),skill.end());
        int i=0;
        int j=n-1;
        long long ans = 0;
        while(i<j){
            if(skill[i] + skill[j] != target)return -1;
            else{
                ans += (skill[i]*skill[j]);
            }
            i++;j--;
        }
        return ans;
    }
};