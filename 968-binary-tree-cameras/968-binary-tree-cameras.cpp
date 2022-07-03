class Solution {
public:
    
    int cam=0;
    
    set<TreeNode*>S;
    
    void dfs(TreeNode*root,TreeNode*parent){
        
        if(root!=NULL){
            
            dfs(root->left,root);
            dfs(root->right,root);
            
            if((parent==NULL && S.find(root)==S.end()) || S.find(root->left)==S.end() || S.find(root->right)==S.end()){
                
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
        
        dfs(root,NULL);
        
        return cam;
        
    }
};