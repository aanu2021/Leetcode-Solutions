class Solution {
public:
    
    TreeNode*helper(TreeNode* root){
        if(!root) return NULL;
        TreeNode*leftChild = root->left;
        TreeNode*rightChild = root->right;
        if(leftChild == NULL) return rightChild;
        if(rightChild == NULL) return leftChild;
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
            root = helper(root);
        }
        TreeNode*tmp = root;
        while(tmp){
            if(tmp->left && tmp->val > key){
                if(tmp->left && tmp->left->val == key){
                    tmp->left = helper(tmp->left);
                    return root;
                }
                else{
                    tmp = tmp->left;
                }
            }
            else if(tmp->right && tmp->val < key){
                if(tmp->right && tmp->right->val == key){
                    tmp->right = helper(tmp->right);
                    return root;
                }
                else{
                    tmp = tmp->right;
                }
            }
            else{
                return root;
            }
        }
        return root;
    }
};