class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        
        if(!root){
            return {};
        }
        
        vector<int>preorder;
        
        TreeNode*curr=root;
        
        while(curr){
            
            if(curr->left==NULL){
                
                preorder.push_back(curr->val);
                curr=curr->right;
                
            }
            
            else{
                
                TreeNode*prev=curr->left;
                
                while(prev && prev->right && prev->right!=curr){
                    
                    prev=prev->right;
                    
                }
                
                if(prev->right==NULL){
                    
                    preorder.push_back(curr->val);
                    
                    prev->right=curr;
                    
                    curr=curr->left;
                    
                }
                
                else{
                    
                    prev->right=NULL;
                    
                    curr=curr->right;
                    
                }
                
            }
            
        }
        
        return preorder;
        
    }
};