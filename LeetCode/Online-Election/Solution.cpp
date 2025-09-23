class TopVotedCandidate {
public:

    unordered_map<int,int>m;
    vector<int>maxVotes;
    vector<int>t;
    
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int maxi = 0,cand = -1;
        for(int i=0;i<times.size();i++){
            m[persons[i]]+=1;
            if(m[persons[i]]>=maxi){
                maxi = m[persons[i]];
                cand = persons[i];
            }
            maxVotes.push_back(cand);
        }
        t = times;
      
    }
    
    int q(int time) {
        int ind = lower_bound(t.begin(),t.end(),time) - t.begin();
        if(ind >= t.size()) ind = t.size()-1;
        if(t[ind]>time)ind--;
       
        return maxVotes[ind];


    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */