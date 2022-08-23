class Solution {
public:
    
    /*
    
    Time Complexity  : O(H)
    Space Complexity : O(1)    
    
    */
    
    TreeNode*findlastRight(TreeNode*&root){
        
        if(root==NULL){
            return NULL;
        }
        
        TreeNode*curr=root;
        
        while(curr->right!=NULL){
            curr=curr->right;
        }
        
        return curr;
        
    }
    
    TreeNode*helper(TreeNode*&root){
        
        if(root==NULL){
            return NULL;
        }
        
        if(root->left==NULL){
            return root->right;
        }
        
        else if(root->right==NULL){
            return root->left;
        }
        
        
        TreeNode*rightchild=root->right;
        
        TreeNode*lastright=findlastRight(root->left);
        
        lastright->right=rightchild;
        
        return root->left;
        
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(!root){
            return NULL;
        }
        
        if(root->val==key){
            return helper(root);
        }
        
        TreeNode*dummy=root;
        
        while(root){
            
            if(root->val>key){
                
                if(root->left && root->left->val==key){
                    
                    root->left=helper(root->left);
                    break;
                    
                }
                
                else{
                    
                    root=root->left;
                    
                }
                
            }
            
            else{
                
                if(root->right && root->right->val==key){
                    
                    root->right=helper(root->right);
                    break;
                    
                }
                
                else{
                    
                    root=root->right;
                    
                }
                
            }
            
        }
        
        return dummy;
        
    }
};