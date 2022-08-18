class Solution {
public:
    
    vector<int> preorderTraversal(TreeNode* root) {
        
      vector<int>preorder;
        
        if(root==NULL){
            return {};
        }
        
        stack<TreeNode*>S;
        
        S.push(root);
        
        while(!S.empty()){
            
            auto curr=S.top();
            S.pop();
            
            preorder.push_back(curr->val);
            
            if(curr->right){
                S.push(curr->right);
            }
            
            if(curr->left){
                S.push(curr->left);
            }
            
        }
        
        return preorder;
        
    }
};