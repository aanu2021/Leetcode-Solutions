class Solution {
public:
    
    typedef long long ll;
    
    bool isvalid(TreeNode*root,ll minrange,ll maxrange){
        
        if(root==NULL){
            
            return true;
            
        }
        
        if(root->val<minrange || root->val>maxrange){
            
            return false;
            
        }
        
        
        bool left=true;
        bool right=true;
        
        if(root->left){
            
            left=isvalid(root->left,minrange,(ll)root->val-1);
            
        }
        
        if(root->right){
            
            right=isvalid(root->right,(ll)root->val+1,maxrange);
            
        }
        
        return left&&right;
        
    }
    
    bool isValidBST(TreeNode* root) {
        
        if(root==NULL){
            
            return true;
            
        }
        
        return isvalid(root,-1e14,1e14);
        
    }
};