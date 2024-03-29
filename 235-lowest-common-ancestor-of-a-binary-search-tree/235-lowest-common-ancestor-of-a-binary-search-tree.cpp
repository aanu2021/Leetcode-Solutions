class Solution {
public:
    
    TreeNode*lca(TreeNode*&root,TreeNode*&p,TreeNode*&q){
        
        if(!root){
            return NULL;
        }
        
        if(p->val > root->val && q->val > root->val){
            
            return lca(root->right,p,q);
            
        }
        
        else if(p->val < root->val && q->val < root->val){
            
            return lca(root->left,p,q);
            
        }
        
        else{
            
            return root;
            
        }
        
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
     
        if(!root){
            return NULL;
        }
        
        TreeNode*curr=root;
        
        while(curr){
            
            if(p->val > curr->val && q->val > curr->val){

                curr=curr->right;

            }

            else if(p->val < curr->val && q->val < curr->val){

                curr=curr->left;

            }

            else{

                break;

            }
            
        }
        
        return curr;
        
    }
};