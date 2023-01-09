class Solution {
public:
    
    void postorder_recursive(TreeNode*&root,vector<int>&postorder_arr)
    {
        if(!root) return;
        postorder_recursive(root->left,postorder_arr);
        postorder_recursive(root->right,postorder_arr);
        postorder_arr.push_back(root->val);
    }
    
    void postorder_iterative(TreeNode*&root,vector<int>&postorder_arr)
    {
        if(!root) return;
        stack<TreeNode*>S;
        S.push(root);
        
        while(!S.empty()){
            auto node = S.top();
            S.pop();
            postorder_arr.push_back(node->val);
            if(node->left) S.push(node->left);
            if(node->right) S.push(node->right);
        }
        
        reverse(postorder_arr.begin(),postorder_arr.end());
        
    }    
    
    vector<int> postorderTraversal(TreeNode* root) {
        
        if(!root) return {};
        vector<int>postorder_arr;
        // postorder_recursive(root,postorder_arr);
        postorder_iterative(root,postorder_arr);
        return postorder_arr;
        
    }
};