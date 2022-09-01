class Solution {
    
    public:
    
    unordered_set<TreeNode*>S;
    
    int cam=0;
    
    void func(TreeNode*&root,TreeNode*&parent){
        
        if(!root){
            return;
        }
        
        func(root->left,root);
        func(root->right,root);
        
        if((parent==NULL && S.find(root)==S.end()) || S.find(root->left)==S.end() || S.find(root->right)==S.end()){
            
            cam++;
            
            S.insert(root);
            S.insert(parent);
            S.insert(root->left);
            S.insert(root->right);
            
        }
        
    }
    
    int minCameraCover(TreeNode* root) {
        
        if(!root){
            return 0;
        }
      
        cam=0;
        
        S.insert(NULL);
        
        TreeNode*par=NULL;
        
        func(root,par);
        
        return cam;
        
    }
};