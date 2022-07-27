class Solution {
public:
    void flatten(TreeNode* root) {
        
        if(root==NULL){
            return;
        }
        
        TreeNode*tempLeft=root->left;
        TreeNode*tempRight=root->right;
        
        root->left=NULL;
        
        flatten(tempLeft);
        flatten(tempRight);
        
        root->right=tempLeft;
        
        TreeNode*current=root;
        
        while(current->right!=NULL){
            
            current=current->right;
            
        }
        
        current->right=tempRight;
        
    }
};