class Solution {
public:
    
    /*
    
     Though it is not an optimization , but we can come up with
     an iterative version. of these problem. 
    
    */
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        TreeNode*curr=root;
        
        while(curr){
            
            if((curr->val>p->val) && (curr->val>q->val)){
                curr=curr->left;
            }
            
            else if((curr->val<p->val) && (curr->val<q->val)){
                curr=curr->right;
            }
            
            else{
                break;
            }
            
        }
        
        return curr;
        
    }
};