class Solution {
public:
    
    TreeNode*helper(TreeNode* &root){
        if(!root) return NULL;
        if(!root->left) return root->right;
        if(!root->right) return root->left;
        TreeNode*leftChild = root->left;
        TreeNode*rightChild = root->right;
        while(leftChild && leftChild->right){
            leftChild = leftChild->right;
        }
        leftChild->right = rightChild;
        root->right = NULL;
        return root->left;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        if(root->val == key){
            return helper(root);
        }
        TreeNode*tmp = root;
        while(tmp){
            if(tmp->val > key){
                if(tmp->left && tmp->left->val == key){
                    tmp->left = helper(tmp->left);
                    return root;
                }
                else{
                    tmp = tmp->left;
                }
            }
            else{
                if(tmp->right && tmp->right->val == key){
                    tmp->right = helper(tmp->right);
                    return root;
                }
                else{
                    tmp = tmp->right;
                }
            }
        }
        return root;
    }
};