class Solution {
public:
    
    void preorder_recursive(TreeNode*&root,vector<int>&preorder_arr)
    {
        if(!root) return;
        preorder_arr.push_back(root->val);
        preorder_recursive(root->left,preorder_arr);
        preorder_recursive(root->right,preorder_arr);
    }  
    
    void preorder_iterative(TreeNode*&root,vector<int>&preorder_arr)
    {
        
        if(!root) return ;
        
        stack<TreeNode*>S;
        S.push(root);
        
        while(!S.empty()){
            
            auto node = S.top();
            S.pop();
            
            preorder_arr.push_back(node->val);
            
            if(node->right){
                S.push(node->right);
            }
            if(node->left){
                S.push(node->left);
            }
            
        }
        
    }    
    
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int>preorder_arr;
        // preorder_recursive(root,preorder_arr);
        preorder_iterative(root,preorder_arr);
        return preorder_arr;
    }
};