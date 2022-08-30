class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        
        if(!root){
            return {};
        }
        
        vector<int>preorder;
        
        stack<TreeNode*>S;
        
        S.push(root);
        
        while(!S.empty()){
            
            auto node=S.top();
            S.pop();
            
            preorder.push_back(node->val);
            
            if(node->right){
                
                S.push(node->right);
                
            }
            
            if(node->left){
                
                S.push(node->left);
                
            }
            
        }
        
        return preorder;
        
    }
};