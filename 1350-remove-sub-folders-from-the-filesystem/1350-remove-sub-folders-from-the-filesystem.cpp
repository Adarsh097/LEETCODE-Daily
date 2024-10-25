class Solution {
public:
    bool solve(string s1, string s2){
        int i=1,j=1;
        s1+='/';
        s2+='/';
        string temp1 = "", temp2 = "";
        while(i<s1.size()){
            while(s1[i] != '/'){
                temp1 += s1[i++];
            }
            while(s2[j] != '/'){
                temp2 += s2[j++];
            }

            if(temp1 != temp2)return false;
            else{
                i++;
                j++;
                if(i==s1.size() && j<s2.size())return true;
            }
        }
        return false;
    }
    vector<string> removeSubfolders(vector<string>& folder) {
        if(folder.size() <= 1)return folder;

        int n = folder.size();
        sort(folder.begin(),folder.end());
        vector<string>ans;
        string str1 = folder[0];
        int j = 1;
        while(j<n){
            string str2 = folder[j];
            bool compare = solve(str1,str2);

            //if str2 is subfolder of str1
            if(compare){
                j++;
            }else{
                ans.push_back(str1);
                str1 = str2;
                j++;
            }
        }
        ans.push_back(str1);
        return ans;


    }
};