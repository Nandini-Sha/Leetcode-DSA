class WordDictionary {
private:
    struct Node{
        Node* child[26];
        bool end;

        Node(){
            end = false;
            for(int i = 0;i<26;i++) child[i] = NULL;
        }
    };Node* root;
public:
bool dfs(string &word, int pos, Node* n){
        if(n==NULL) return false;
        if(pos==word.size()) return n->end;
        char c = word[pos];
        if(c=='.'){
            for(int i = 0;i<26;i++){
                if(n->child[i] && dfs(word,pos+1,n->child[i])) return true;
            }
            return false;
        }
        int i = c-'a';
        return dfs(word,pos+1,n->child[i]);
    }
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* n = root;
        for(char c:word){
            int i = c - 'a';
            if(n->child[i] == NULL){
                n->child[i] = new Node();
            }
            n = n->child[i];
        }
        n->end = true;
    }
    
    bool search(string word) {
        return dfs(word,0,root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */