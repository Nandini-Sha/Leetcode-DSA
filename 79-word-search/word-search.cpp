class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(word[0]==board[i][j]){
                    if(back(board, word, i, j, 0)) return true;
                }
            }
        }

        return false;
    }
    bool back(vector<vector<char>>& board, string word, int a, int b, int i){
        if(i == word.size()) return true;
        if(a<0 || b<0 || a>=board.size() || b>=board[0].size() || board[a][b] != word[i]) return false;

        char t = board[a][b];
        board[a][b] = '#';

        bool found = back(board, word, a+1, b, i+1) || back(board, word, a, b+1, i+1) || back(board, word, a-1, b, i+1) || back(board, word, a, b-1, i+1);

        board[a][b] = t;

        return found;
    }
};