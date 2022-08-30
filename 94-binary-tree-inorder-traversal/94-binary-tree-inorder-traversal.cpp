class Solution {
public:
    
    /*
    
    Morris Traversal : Rightmost node of the left subtree is linked with the current node , with an imaginary thread.
    
    Time Complexity  : O(N)
    Space Complexity : O(1)
    
    */
    
    vector<int> inorderTraversal(TreeNode* root) {
     
        if(!root){
            return {};
        }
        
        vector<int>inorder;
        
        TreeNode*curr=root;
        
        while(curr!=NULL){
            
            if(curr->left==NULL){
                
                inorder.push_back(curr->val);
                curr=curr->right;
                
            }
            
            else{
                
                TreeNode*prev=curr->left;
                
              while(prev && prev->right && prev->right!=curr){
                    
                    prev=prev->right;
                    
                }
                
                if(prev->right==NULL){
                    
                    prev->right=curr;
                    
                    curr=curr->left;
                    
                }
                
                else{
                    
                    prev->right=NULL;
                    
                    inorder.push_back(curr->val);
                    
                    curr=curr->right;
                    
                }
                
            }
            
        }
        
        return inorder;
        
    }
};