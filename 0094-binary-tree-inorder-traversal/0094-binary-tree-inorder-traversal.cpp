class Solution {
public:
    
    void inorder_recursive(TreeNode*&root,vector<int>&inorder_arr)
    {
        
        if(!root) return;
        inorder_recursive(root->left,inorder_arr);
        inorder_arr.push_back(root->val);
        inorder_recursive(root->right,inorder_arr);
        
    }    
    
    vector<int> inorderTraversal(TreeNode* root) {
        
        if(!root) return {};
        vector<int>inorder_arr;
        inorder_recursive(root,inorder_arr);
        return inorder_arr;
        
    }
};