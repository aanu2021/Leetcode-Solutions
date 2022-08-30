class Solution {
public:
    
    typedef long long ll;
    
    bool isValid(TreeNode*&root,ll lval,ll rval){
        
        if(!root){
            return true;
        }
        
        if(root->val<lval || root->val>rval){
            return false;
        }
        
        bool lsubtree=isValid(root->left,(ll)lval,(ll)root->val-1);
        
        bool rsubtree=isValid(root->right,(ll)root->val+1,(ll)rval);
        
        return lsubtree && rsubtree; 
        
    }
    
    bool isValidBST(TreeNode* root) {
        
        if(!root){
            return true;
        }
        
        return isValid(root,(ll)-1e14,(ll)1e14);
        
    }
};