class Solution {
public:
    
    bool isSym(TreeNode*&p , TreeNode*&q){
        if(!p && !q) return true;
        if(!p || !q) return false;
        if(p->val != q->val) return false;
        return isSym(p->left,q->right) && isSym(p->right,q->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        if(!root->left && !root->right) return true;
        return isSym(root->left,root->right);
    }
};