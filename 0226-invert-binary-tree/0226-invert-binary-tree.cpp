class Solution {
public:
    
    void doInversion(TreeNode* root){
        if(!root) return;
        TreeNode*leftSubTree = root->left;
        TreeNode*rightSubTree = root->right;
        root->left = rightSubTree;
        root->right = leftSubTree;
        doInversion(root->left);
        doInversion(root->right);
    }
    
    TreeNode* invertTree(TreeNode* root) {
        doInversion(root);
        return root;
    }
};