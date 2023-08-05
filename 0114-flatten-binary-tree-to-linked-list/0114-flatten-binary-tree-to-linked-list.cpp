class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root) return;
        if(!root->left && !root->right) return;
        flatten(root->left);
        flatten(root->right);
        TreeNode*leftChild = root->left;
        TreeNode*rightChild = root->right;
        root->left = NULL;
        root->right = leftChild;
        TreeNode*tmp = root;
        while(tmp && tmp->right){
            tmp = tmp->right;
        }
        tmp->right = rightChild;
    }
};