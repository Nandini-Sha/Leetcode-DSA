/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) return "NULL$";

        string serial = "";
        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty()){
            TreeNode* node = que.front();
            que.pop();

            if(node){
                serial += to_string(node->val);
                que.push(node->left);
                que.push(node->right);
            }
            else{
                serial += "NULL";
            }

            serial += "$";
        }
        cout<<serial<<endl;
        return serial;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "NULL$") return NULL;
        vector<string> token;
        string temp = "";

        for(char c : data){
            if(c == '$'){
                token.push_back(temp);
                temp = "";
            }
            else{
                temp += c;
            }
        }

        TreeNode* root = new TreeNode(stoi(token[0]));

        queue<TreeNode*> q;
        q.push(root);
        int i = 1;
        while(!q.empty() && i<token.size()){
            TreeNode* parent = q.front();
            q.pop();

            if(token[i]!="NULL"){
                TreeNode* LeftNode = new TreeNode(stoi(token[i]));
                parent->left = LeftNode;
                q.push(LeftNode);
            }
            i++;
            if(token[i]!="NULL"){
                TreeNode* RightNode = new TreeNode(stoi(token[i]));
                parent->right = RightNode;
                q.push(RightNode);
            }
            i++;
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));