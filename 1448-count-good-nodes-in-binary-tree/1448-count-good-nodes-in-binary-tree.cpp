class Solution {
public:
    
    int func(TreeNode*root,int maxx){
        
        if(root==NULL){
            return 0;
        }
        
        maxx=max(maxx,root->val);
        
        if(root->val>=maxx){
            
            return 1 + func(root->left,root->val) + func(root->right,root->val);
            
        }
        
        else{
            
            return func(root->left,maxx) + func(root->right,maxx);
            
        }
        
    }
    
    int goodNodes(TreeNode* root) {
        
        if(root==NULL){
            return 0;
        }
        
        return func(root,root->val);
        
    }
};