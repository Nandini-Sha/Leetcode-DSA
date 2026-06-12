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
public:
    int preIndex = 0;
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int l, int r){
        if(l>r) return NULL;
        int rootval = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootval);
        int pos = l;
        while(inorder[pos]!=rootval) pos++;
        root->left = build(preorder, inorder, l, pos-1);
        root->right = build(preorder, inorder, pos+1, r);

        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, 0, inorder.size()-1);
    }
};