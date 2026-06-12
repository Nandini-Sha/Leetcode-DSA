/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private: 
    vector<int> res;
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(root == NULL) return res;
        queue<TreeNode*> Que;
        Que.push(root);
        while(!Que.empty()){
            int s = Que.size();
            for(int i = 0;i<s;i++){
                TreeNode* Node = Que.front();
                Que.pop();
                if(i == (s-1)) res.push_back(Node->val);

                if(Node->left) Que.push(Node->left);
                if(Node->right) Que.push(Node->right);
            }
        }


        return res;

    }
};