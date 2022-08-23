class Solution {
public:
    
    TreeNode*findlastRight(TreeNode*&root){
        
        if(root->right==NULL){
            return root;
        }
        
        return findlastRight(root->right);
        
    }
    
    TreeNode*helper(TreeNode*&root){
        
        if(root->left==NULL){
            return root->right;
        }
        
        else if(root->right==NULL){
            return root->left;
        }

        TreeNode*rightChild=root->right;
        
        TreeNode*lastchild=findlastRight(root->left);
        
        lastchild->right=rightChild;
        
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
                
                if(root->left!=NULL && root->left->val==key){
                    
                    root->left=helper(root->left);
                    break;
                    
                }
                
                else{
                    
                    root=root->left;
                    
                }
                
            }
            
            else{
                
                if(root->right!=NULL && root->right->val==key){
                    
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