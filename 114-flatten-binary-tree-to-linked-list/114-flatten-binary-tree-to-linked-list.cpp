class Solution {
public:
    
    void flatten(TreeNode* root) {
        
        if(!root){
            return;
        }
        
        
        stack<TreeNode*>S;
        
        S.push(root);
        
        while(!S.empty()){
            
            auto node=S.top();
            S.pop();
            
            if(node->right){
                S.push(node->right);
            }
            
            if(node->left){
                S.push(node->left);
            }
            
            if(!S.empty()){
                
                node->right=S.top();
                
            }
            
            node->left=NULL;
            
        }
        
    }
};