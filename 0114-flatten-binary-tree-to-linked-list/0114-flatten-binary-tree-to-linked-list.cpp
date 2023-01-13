
class Solution {
public:
    void flatten(TreeNode* root) {
       
        if(!root) return;
        
        if(!root->left && !root->right) return;
        
        flatten(root->left);
        flatten(root->right);
        
        TreeNode*leftChild = root->left;
        TreeNode*rightChild = root->right;
        
        root->left = NULL;
        root->right = leftChild;
        TreeNode*curr = root;
        while(curr && curr->right){
            curr = curr->right;
        }
        curr->right = rightChild;
        
    }
};