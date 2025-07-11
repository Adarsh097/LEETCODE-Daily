class Solution {
public:
    int m,n;
    unordered_map<string,bool>map;
    bool solve(string &s, string &p, int ind1, int ind2){
        if(ind2==n)return (ind1==m);
        string temp = to_string(ind1) + to_string(ind2);
        if(map.find(temp)!=map.end())return map[temp];
     

        bool firstMatch = (ind1<m && (s[ind1]==p[ind2] || p[ind2]=='.'));
        if(ind2+1<n && p[ind2+1]=='*'){
            return map[temp] = solve(s,p,ind1,ind2+2) || (firstMatch && solve(s,p,ind1+1,ind2));
        }
        else if(firstMatch){
            return map[temp] = solve(s,p,ind1+1,ind2+1);
        }
        
        return map[temp] = false;
    }
    bool isMatch(string s, string p) {
        m = s.size(), n = p.size();
        int ans = solve(s,p,0,0);
        return ans;
    }
};
