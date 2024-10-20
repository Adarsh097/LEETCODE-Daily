class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string>ans;
        int n = target.size();
        string temp = "";
        for(int i=0;i<n;i++){
           char t = target[i];
           for(char ch='a';ch<='z';ch++){
            if(ch==t){
                temp.push_back(ch);
                ans.push_back(temp);
                break;
            }else{
                temp.push_back(ch);
                ans.push_back(temp);
                temp.pop_back();
            }
            
           }
           

        }
        return ans;
    }
};