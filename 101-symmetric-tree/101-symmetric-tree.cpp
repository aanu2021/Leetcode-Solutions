class Solution {
public:
    
    bool isCheck(TreeNode*&root1,TreeNode*root2){
        
        if(root1==NULL && root2==NULL){
            return true;
        }
        
        if(root1==NULL || root2==NULL || root1->val!=root2->val){
            return false;
        }
        
        return isCheck(root1->left,root2->right) && isCheck(root1->right,root2->left);
        
    }
    
    bool isSymmetric(TreeNode* root) {
        
        if(!root){
            return true;
        }
        
        return isCheck(root->left,root->right);
        
    }
};
             