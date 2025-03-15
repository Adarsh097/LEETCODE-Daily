class Spreadsheet {
public:
    vector<vector<int>>arr;
    Spreadsheet(int rows) {
        arr.resize(rows+1,vector<int>(27,0));
    }
    
    void setCell(string cell, int value) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1));
        arr[row][col] = value;
    }
    
    void resetCell(string cell) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1));
        arr[row][col] = 0;
    }
    
    int getValue(string formula) {
        string str1 = "",str2 = "";
        bool flag = true;
        for(int i=1;i<formula.size();i++){
            if(formula[i]=='+'){
                flag = false;
                continue;
            }
            if(flag){
                str1 += formula[i];
            }else{
                str2 += formula[i];
            }
            
        }
        int num1 = 0, num2 = 0;
        if(isdigit(str1[0]))num1 = stoi(str1);
        else{
            int col = str1[0] - 'A';
           int row = stoi(str1.substr(1));
            num1 = arr[row][col];
        }
        if(isdigit(str2[0]))num2 = stoi(str2);
        else{
            int col = str2[0] - 'A';
           int row = stoi(str2.substr(1));
            num2 = arr[row][col];
        }
        return num1 + num2;
    }
};