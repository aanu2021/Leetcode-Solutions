class Solution {
public:

    void flatten(TreeNode* root) {
        
        if(!root){
            return;
        }
        
        TreeNode*curr=root;
        
        while(curr!=NULL){
            
            if(curr->left!=NULL){
                
                TreeNode*prev=curr->left;
                
                while(prev!=NULL && prev->right!=NULL){
                    
                    prev=prev->right;
                    
                }
                
                prev->right=curr->right;
                
                curr->right=curr->left;
                
                curr->left=NULL;
                
            }
            
            curr=curr->right;
            
        }
        
        
    }
};