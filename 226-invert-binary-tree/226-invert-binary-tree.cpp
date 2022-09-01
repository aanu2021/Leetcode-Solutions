/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void func(TreeNode*&root){
        
        if(!root){
            return;
        }
        
        TreeNode*tempLeft=root->left;
        TreeNode*tempRight=root->right;
        
        root->left=tempRight;
        root->right=tempLeft;
        
        func(root->left);
        func(root->right);
        
    }
    
    TreeNode* invertTree(TreeNode* root) {
       
        if(!root){
            return NULL;
        }
        
        func(root);
        
        return root;
        
    }
};