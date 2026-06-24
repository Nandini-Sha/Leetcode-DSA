class Solution {
private:
    struct Node {
        Node* child[26];
        string word;

        Node() {
            word = "";
            for(int i = 0; i < 26; i++) child[i] = NULL;
        }
    };

    void insert(Node* root, string &word){
        Node* node = root;
        for(char c : word){
            int idx = c - 'a';
            if(node->child[idx] == NULL)
                node->child[idx] = new Node();
            node = node->child[idx];
        }
        node->word = word; // mark end
    }

    void dfs(vector<vector<char>>& board, int i, int j, Node* node, vector<string>& ans){
        char c = board[i][j];

        if(c == '#' || node->child[c - 'a'] == NULL) return;

        node = node->child[c - 'a'];

        if(node->word != ""){
            ans.push_back(node->word);
            node->word = ""; 
        }

        char temp = board[i][j];
        board[i][j] = '#';

        int m = board.size();
        int n = board[0].size();

        if(i > 0) dfs(board, i-1, j, node, ans);
        if(j > 0) dfs(board, i, j-1, node, ans);
        if(i < m-1) dfs(board, i+1, j, node, ans);
        if(j < n-1) dfs(board, i, j+1, node, ans);

        board[i][j] = temp;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Node* root = new Node();

        for(auto &word : words){
            insert(root, word);
        }

        vector<string> ans;

        int m = board.size();
        int n = board[0].size();

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                dfs(board, i, j, root, ans);
            }
        }

        return ans;
    }
};