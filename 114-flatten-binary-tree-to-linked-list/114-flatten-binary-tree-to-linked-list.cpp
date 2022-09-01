class Solution {
public:
    
    TreeNode*prev=NULL;
    
    void flatten(TreeNode* root) {
        
        if(!root){
            return;
        }
        
        flatten(root->right);
        flatten(root->left);
        
        root->left=NULL;
        
        root->right=prev;
        
        prev=root;
        
    }
};