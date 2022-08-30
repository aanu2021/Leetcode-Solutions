class Solution {
public:
    
    TreeNode*helper(TreeNode*&root){
        
        if(!root){
            return NULL;
        }
        
        if(root->left==NULL){
            return root->right;
        }
        
        if(root->right==NULL){
            return root->left;
        }
        
        TreeNode*rightchild=root->right;
        
        TreeNode*lastRightchild=root->left;
        
        while(lastRightchild && lastRightchild->right){
            
            lastRightchild=lastRightchild->right;
            
        }
        
        lastRightchild->right=rightchild;
        
        return root->left;
        
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(!root){
            return NULL;
        }
        
        if(root->val==key){
            return helper(root);
        }
        
        TreeNode*curr=root;
        
        while(curr!=NULL){
            
            if(curr->val>key){ // Explore the Left subtree
                
                if(curr->left && curr->left->val==key){
                    
                    curr->left=helper(curr->left);
                    break;
                    
                }
                
                else{
                    
                    curr=curr->left;
                    
                }
                
            }
            
            else{ // Explore the Right subtree 
                
                if(curr->right && curr->right->val==key){
                    
                    curr->right=helper(curr->right);
                    break;
                    
                }
                
                else{
                    
                    curr=curr->right;
                    
                }
                
            }
            
        }
        
        return root;
        
    }
};