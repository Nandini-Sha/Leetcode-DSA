class Solution {  
private:
    vector<vector<string>> ans;
public:
    bool check(vector<string> &board, int i, int j){
        int n = board.size();
        for(int a = 0;a<n;a++){
            if(a!=j && board[i][a]=='Q') return false;
        }
        for(int a = 0;a<n;a++){
            if(a!=i && board[a][j]=='Q') return false;
        }
        int a = i+1, b = j+1;
        while(a<n && b<n){
            if(board[a][b] == 'Q') return false;
            a++,b++;
        }
        a = i-1, b = j+1;
        while(a>=0 && b<n){
            if(board[a][b] == 'Q') return false;
            a--,b++;
        }
        a = i+1, b = j-1;
        while(a<n && b>=0){
            if(board[a][b] == 'Q') return false;
            a++,b--;
        }
        a = i-1, b = j-1;
        while(a>=0 && b>=0){
            if(board[a][b] == 'Q') return false;
            a--,b--;
        }
        return true;
    }
    vector<vector<string>> solveNQueens(int n) { 
        vector<string> temp(n,string(n,'.'));
        back(temp, n, 0);

        return ans;
    }

    void back(vector<string> &temp, int n, int a){
        if(a==n){
            ans.push_back(temp);
            return;
        }
        for(int i = 0;i<n;i++){
            temp[i][a] = 'Q';
            if(check(temp,i,a)){
                back(temp,n,a+1);
            }
            temp[i][a] = '.';
        }
    }
};