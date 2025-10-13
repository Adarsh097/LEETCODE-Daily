class Bank {
public:
    unordered_map<int,long long>m;
    int size;
    Bank(vector<long long>& balance) {
        size = balance.size();
        for(int i=0;i<balance.size();i++){
            m[i+1] = balance[i];
        }
    }
    bool isAccountValid(int account){
        return account >=1 && account <=m.size();
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(!isAccountValid(account1) || !isAccountValid(account2))return false;
        if(m[account1]<money)return false;
        m[account1]-=money;
        m[account2]+=money;
        return true;        
    }
    
    bool deposit(int account, long long money) {
        if(!isAccountValid(account))return false;
        m[account]+=money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(!isAccountValid(account))return false;
        if(m[account]>=money){
            m[account]-=money;
            return true;
        }
        return false;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */