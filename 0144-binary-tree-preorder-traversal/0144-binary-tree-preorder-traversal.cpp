class Solution {
public:
    
    void preorder_recursive(TreeNode*&root,vector<int>&preorder_arr)
    {
        if(!root) return;
        preorder_arr.push_back(root->val);
        preorder_recursive(root->left,preorder_arr);
        preorder_recursive(root->right,preorder_arr);
    }    
    
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int>preorder_arr;
        preorder_recursive(root,preorder_arr);
        return preorder_arr;
    }
};