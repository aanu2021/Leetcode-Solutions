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
        
        
        TreeNode*lastchild=root->left;
        
        while(lastchild && lastchild->right){
            
            lastchild=lastchild->right;
            
        }
        
        lastchild->right=rightchild;
        
        root->right=NULL;
        
        return root->left;
        
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        /*
        
           5
          / \
         3   6
        / \   \
       2  4    7  
        
               .Case 1 : Node is a leaf node
               .Case 2 : Node has exactly one child(left/right)
               Case 3 : Node has exactly two children
               .Case 4 : Node does not exist in the given BST    
               
               3    
              / \     
             2   4
                  \
                   6
                    \
                     7
                     
                     */
        
          
          /* Code Begins */
        
         if(!root){
             
             return NULL;
             
         }
        
         if(root->val==key){
             
             return helper(root);
             
         }
        
         TreeNode*curr=root;
        
         while(curr){
             
             if(curr->val>key){
                 
                 if(curr->left && curr->left->val==key){
                     
                     curr->left=helper(curr->left);
                     break;
                     
                 }
                 
                 else{
                     
                     curr=curr->left;
                     
                 }
                 
             }
             
             else{
                 
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