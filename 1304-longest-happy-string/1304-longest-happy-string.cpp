class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>>pq;
        if(a>0)pq.push({a,'a'});
        if(b>0)pq.push({b,'b'});
        if(c>0)pq.push({c,'c'});
        string str = "";
        while(pq.size()>1){
            auto p1 = pq.top();
            pq.pop();
            auto p2 = pq.top();
            pq.pop();

            if(p1.first>=2){
                str += string(2,p1.second);
                p1.first -=2;
            }else{
                str += p1.second;
                p1.first--;
            }

            if(p2.first >=2 && p2.first >= p1.first){
                str += string(2,p2.second);
                p2.first -= 2;
            }else{
                str += p2.second;
                p2.first--;
            }
            if(p1.first >0)pq.push(p1);
            if(p2.first >0)pq.push(p2);
        }
        if(!pq.empty()){
        if(pq.top().first >=2){
            str += string(2,pq.top().second);
            cout<<"here"<<endl;
        }else{
            str += pq.top().second;
        }
        }
        return str;
    }
};