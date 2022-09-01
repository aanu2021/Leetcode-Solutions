class Solution {
public:
    
    int good_nodes=0;
    
    int func(TreeNode*&root,int maxx){
        
        if(!root){
            return 0;
        }
        
        if(root->val>=maxx){
            
            return 1 + func(root->left,root->val) + func(root->right,root->val);
            
        }
        
        else{
            
            return func(root->left,maxx) + func(root->right,maxx);
            
        }
        
    }
    
    int goodNodes(TreeNode* root) {
        
        if(!root){
            return 0;
        }
        
        return func(root,root->val);
        
    }
};