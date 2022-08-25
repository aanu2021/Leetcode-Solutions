class Solution {
public:
    
    
    void flatten(TreeNode* root) {
        
        if(!root){
            return;
        }
        
        TreeNode*tempLeft=root->left;
        TreeNode*tempRight=root->right;
        
        root->left=NULL;
        
        flatten(tempLeft);
        flatten(tempRight);
        
        root->right=tempLeft;
        
        TreeNode*curr=root;
        
        while(curr!=NULL && curr->right!=NULL){
            
            curr=curr->right;
            
        }
        
        curr->right=tempRight;
        
    }
};