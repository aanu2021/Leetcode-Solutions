class Solution {
public:
    
    /*
    
    Validate a BST --> Validate every Node --> validate every node means for a particular node all the nodes in its left subtree should be smaller than the node->val and all the nodes in its right subtree should be greater then the node->val.
    
    For these , there are three nodes 1 , 2 , 3.
    
         1
          \
           3
          /
         2
         
     For node (2) , we have its value should be less than node (3) , and node(2) always be in (1)'s right subtree. That means (2)'s value should be strictly greater then (1)'s value , all in all every node's value should lie in a particular range.
     
     
     Node's value [left , right]
    
    */
    
    typedef long long ll;
    
    bool isvalid(TreeNode*root,ll minval,ll maxval){
        
        if(root==NULL){
            return true;
        }
        
        if(root->val<minval || root->val>maxval){
            return false;
        }
        
        bool left=true,right=true;
        
        if(root->left){
            
            left=isvalid(root->left,minval,(ll)root->val-1);
            
        }
        
        if(root->right){
            
            right=isvalid(root->right,(ll)root->val+1,maxval);
            
        }
        
        return left && right;
        
    }
    
    bool isValidBST(TreeNode* root) {
        
        if(root==NULL){
            return true;
        }
        
        return isvalid(root,(ll)-1e14,(ll)1e14);
        
    }
};