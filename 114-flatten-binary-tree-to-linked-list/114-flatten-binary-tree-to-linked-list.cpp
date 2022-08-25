class Solution {
public:
    

    void flatten(TreeNode* root) {
        
        if(!root){
            return;
        }
        
        
        stack<TreeNode*>S;
        
        S.push(root);
        
        
        while(!S.empty()){
            
            auto curr=S.top();
            S.pop();
            
            if(curr->right){
                S.push(curr->right);
            }
            
            if(curr->left){
                S.push(curr->left);
            }
            
            if(!S.empty()){
                curr->right=S.top();
            }else{
                curr->right=NULL;
            }
            
            curr->left=NULL;
            
        }
        
        
    }
};