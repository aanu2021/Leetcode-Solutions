class Solution {
public:
    
    bool func(TreeNode*&root,int target){
        
        // Edge Case //
        
        if(!root) return false;
        
        // Base Case //
        
        if(!root->left && !root->right){
            
            if(root->val == target){
                
                return true;
                
            }
            
            else{
                
                return false;
                
            }
            
        }
        
        if(func(root->left,target-root->val) || func(root->right,target-root->val)){
            
            return true;
            
        }
        
        else{
            
            return false;
            
        }
        
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        if(!root) return false;
        
        return func(root,targetSum);
        
    }
};