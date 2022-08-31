class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        
        if(!root){
            return {};
        }
        
        vector<int>postorder;
        
        stack<TreeNode*>S;
                
        S.push(root);
        
        while(!S.empty()){
            
            auto curr=S.top();
            S.pop();
            
            postorder.push_back(curr->val);
            
            if(curr->left){
                
                S.push(curr->left);
                
            }
            
            if(curr->right){
                
                S.push(curr->right);
                
            }
            
        }
        
        reverse(postorder.begin(),postorder.end());
        
        return postorder;
        
    }
};