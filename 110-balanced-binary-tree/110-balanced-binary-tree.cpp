class Solution {
public:
    
    bool isPossible=true;
    
    int height(TreeNode*&root){
        
        if(!root){
            return 0;
        }
        
        int lht=height(root->left);
        int rht=height(root->right);
     
        
        if(abs(lht-rht)>1){
            isPossible=false;
        }
        
        return 1 + max(lht,rht);
        
    }
    
   
    
    bool isBalanced(TreeNode* root) {
        
        if(!root){
            return true;
        }
        
        int ht=height(root);
        
        return isPossible;
        
    }
};