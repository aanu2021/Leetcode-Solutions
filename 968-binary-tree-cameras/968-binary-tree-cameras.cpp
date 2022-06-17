class Solution {
public:
    
    set<TreeNode*>S;
    int cam=0;
    
    void func(TreeNode*root,TreeNode*parent){
        
        if(root!=NULL){
            
            func(root->left,root);
            func(root->right,root);
            
            if(S.find(root->left)==S.end() || S.find(root->right)==S.end() || (parent==NULL && S.find(root)==S.end())){
                
                cam++;
                
                S.insert(root);
                S.insert(parent);
                S.insert(root->left);
                S.insert(root->right);
                
            }
            
        }
        
    }
    
    int minCameraCover(TreeNode* root) {
        
       if(root==NULL){
           return 0;
       }
        
       S.insert(NULL); 
        
       func(root,NULL); 
        
       return cam; 
        
    }
};