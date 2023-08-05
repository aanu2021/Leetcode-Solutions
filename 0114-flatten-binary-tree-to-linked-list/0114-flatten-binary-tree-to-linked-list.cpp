class Solution {
public:
    void flatten3(TreeNode* root) {
        if(!root) return;
        if(!root->left && !root->right) return;
        flatten3(root->left);
        flatten3(root->right);
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
    TreeNode*prevNode = NULL;
    void flatten(TreeNode* root){
        if(!root) return;
        flatten(root->right);
        flatten(root->left);
        root->left = NULL;
        root->right = prevNode;
        prevNode = root;
    }
};