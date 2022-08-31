class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int>inorder;
        
        if(!root){
            return {};
        }
        
        stack<TreeNode*>S;
        
        TreeNode*curr=root;
        
        while(!S.empty() || curr){
            
            while(curr){
                
                S.push(curr);
                
                curr=curr->left;
                
            }
            
            curr=S.top();
            S.pop();
            
            inorder.push_back(curr->val);
            
            curr=curr->right;
            
        }
        
        return inorder;
        
    }
};