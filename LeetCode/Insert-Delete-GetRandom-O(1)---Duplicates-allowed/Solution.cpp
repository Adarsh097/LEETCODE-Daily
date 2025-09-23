}

bool insert(int val) {
    mp[val]++;
    return mp[val] == 1;
}

bool remove(int val) {
    if(mp.find(val) == mp.end()) return false;
    mp[val]--;
    if(mp[val] == 0) mp.erase(val);
    return true;
}

int getRandom() {
    int step = rand()%mp.size();
    auto it = mp.begin();
    while(step--){
        it++;
    }

    return it->first;
}