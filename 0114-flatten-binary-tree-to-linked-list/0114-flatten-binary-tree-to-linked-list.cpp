class Solution {
public:
    
    void flatten3(TreeNode* root) {
        if(!root) return;
        if(!root->left && !root->right) return;
        flatten3(root->left);
        flatten3(root->right);
        TreeNode*leftChild = root->left;
        TreeNode*rightChild = root->right;
        root->left = NULL;
        root->right = leftChild;
        TreeNode*tmp = root;
        while(tmp && tmp->right){
            tmp = tmp->right;
        }
        tmp->right = rightChild;
    }
    
    TreeNode*prevNode = NULL;
    void flatten2(TreeNode* root){
        if(!root) return;
        flatten2(root->right);
        flatten2(root->left);
        root->left = NULL;
        root->right = prevNode;
        prevNode = root;
    }
    
    void flatten(TreeNode* root){
        if(!root) return;
        TreeNode*curr = root;
        while(curr){
            if(curr->left){
                TreeNode*prev = curr->left;
                while(prev && prev->right){
                    prev = prev->right;
                }
                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
    }
};