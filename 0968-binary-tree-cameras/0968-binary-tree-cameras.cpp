class Solution {
public:
    
    unordered_set<TreeNode*>covered;
    int cam;
    
    void dfs(TreeNode* &root,TreeNode *&parent){
        
        if(!root) return;
        
        dfs(root->left,root);
        dfs(root->right,root);
        
        if((parent==NULL && covered.find(root) == covered.end()) || covered.find(root->left) == covered.end() || covered.find(root->right) == covered.end()){
            
            cam++;
            
            covered.insert(root);
            covered.insert(parent);
            covered.insert(root->left);
            covered.insert(root->right);
            
        }
    }
    
    int minCameraCover(TreeNode* root) {
        
        if(!root) return 0;
        cam = 0;
        
        covered.insert(NULL);
        covered.insert(NULL);
        
        TreeNode * parent = NULL;
        dfs(root,parent);
        return cam;
        
    }
};