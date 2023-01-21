class Solution {
public:
    
    TreeNode * prev = NULL;
    TreeNode * first = NULL;
    TreeNode * second = NULL;
    
    void inorder(TreeNode * root){
        if(!root) return;
        inorder(root->left);
        if(prev && prev->val > root->val){
            if(first == NULL) first = prev;
            second = root;
        }
        prev = root;
        inorder(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        if(!root) return;
        inorder(root);
        swap(first->val,second->val);
    }
};