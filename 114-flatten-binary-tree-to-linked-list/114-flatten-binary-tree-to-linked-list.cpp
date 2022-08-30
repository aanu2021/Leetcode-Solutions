class Solution {
public:
    void flatten(TreeNode* root) {
        
        if(!root){
            return;
        }
        
        TreeNode*tempLeft =root->left;
        TreeNode*tempRight=root->right;
        
        flatten(tempLeft);
        flatten(tempRight);
        
        root->right=tempLeft;
        
        root->left=NULL;
        
        TreeNode*curr=root;
        
        while(curr->right!=NULL){
            curr=curr->right;
        }
        
        curr->right=tempRight;
        
    }
};