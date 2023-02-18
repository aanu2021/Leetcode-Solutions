
class Solution {
public:
    
    void func(TreeNode*&root){
        if(!root) return;
        TreeNode * tempLeft = root->left;
        TreeNode * tempRight = root->right;
        root->left = tempRight;
        root->right = tempLeft;
        func(root->left);
        func(root->right);
    }
    
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        func(root);
        return root;
    }
};