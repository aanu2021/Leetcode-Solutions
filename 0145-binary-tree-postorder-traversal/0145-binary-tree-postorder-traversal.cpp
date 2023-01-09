class Solution {
public:
    
    void postorder_recursive(TreeNode*&root,vector<int>&postorder_arr)
    {
        if(!root) return;
        postorder_recursive(root->left,postorder_arr);
        postorder_recursive(root->right,postorder_arr);
        postorder_arr.push_back(root->val);
    }    
    
    vector<int> postorderTraversal(TreeNode* root) {
        
        if(!root) return {};
        vector<int>postorder_arr;
        postorder_recursive(root,postorder_arr);
        return postorder_arr;
        
    }
};