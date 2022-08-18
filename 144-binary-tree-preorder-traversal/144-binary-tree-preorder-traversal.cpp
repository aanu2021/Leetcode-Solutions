class Solution {
public:
    
    vector<int>preorder_arr;
    
    void preorder(TreeNode*&root){
        
        if(root==NULL){
            return;
        }
        
        preorder_arr.push_back(root->val);
        
        preorder(root->left);
        
        preorder(root->right);
        
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        
        preorder(root);
        
        return preorder_arr;
        
    }
};