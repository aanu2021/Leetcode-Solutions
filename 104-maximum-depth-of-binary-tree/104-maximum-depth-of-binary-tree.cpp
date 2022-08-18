class Solution {
public:
    
    int depth(TreeNode*&root){
        
        if(root==NULL){
            return 0;
        }
        
        int ld=depth(root->left);
        int rd=depth(root->right);
        
        return 1+max(ld,rd);
        
    }
    
    int maxDepth(TreeNode* root) {
        
        if(root==NULL){
            return 0;
        }
        
        int ht=depth(root);
        
        return ht;
        
    }
};