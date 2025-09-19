class Compare{
    public:
    bool operator()(const pair<int,string>&p1,const pair<int,string>&p2){
        if(p1.first == p2.first){
            return p1.second > p2.second;
        }else{
            return p1.first < p2.first;
        }
    }
};
class FoodRatings {
public:
    unordered_map<string,int>fr;
    unordered_map<string,priority_queue<pair<int,string>,vector<pair<int,string>>,Compare>>m;
    unordered_map<string,string>fc;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(int i=0;i<n;i++){
            string food = foods[i], cuisine = cuisines[i];
            int rating = ratings[i];
            fr[food] = rating;
            m[cuisine].push({rating,food});
            fc[food] = cuisine;
        }
    }
    
    void changeRating(string food, int newRating) {
        fr[food] = newRating;
        string cuisine = fc[food];
        m[cuisine].push({newRating,food});

    }
    
    string highestRated(string cuisine) {
        auto &pq = m[cuisine];
        while(!pq.empty()){
            auto it = pq.top();
           
            int rating = it.first; string food = it.second;
            if(fr[food]!=rating){
                 pq.pop();
                 continue;
            }
            else{
                return food;
            }
        }
        return "";
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */