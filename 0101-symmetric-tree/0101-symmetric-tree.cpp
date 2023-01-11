class Solution {
public:
    
    bool isSame(TreeNode*&x,TreeNode*&y){
        if(x==NULL && y==NULL) return true;
        if(x==NULL || y==NULL) return false;
        if(x->val != y->val) return false;
        return isSame(x->left,y->right) && isSame(x->right,y->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return isSame(root->left,root->right);
    }
};