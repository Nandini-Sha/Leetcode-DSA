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
    int ans = 0;
public:
    void dfs(TreeNode* root, int maxi){
        if(root->val>=maxi) ans+=1;
        if(root->left) {
            int maxim = max(maxi,root->left->val);
            dfs(root->left,maxim);
        }
        
        if(root->right) {
            int maxim = max(maxi,root->right->val);  
            dfs(root->right,maxim);
        }
        
    }
        
    int goodNodes(TreeNode* root) {
        if(root == NULL) return ans;
        dfs(root,root->val);

        return ans;
    }
};