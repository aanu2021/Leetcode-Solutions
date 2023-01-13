class Solution {
public:
    
    TreeNode* helper(TreeNode* &root){
        if(root->left == NULL) return root->right;
        if(root->right == NULL) return root->left;
        TreeNode* leftChild = root->left;
        TreeNode* rightChild = root->right;
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
            return root;
        }
        
        TreeNode* temp = root;
        while(root){
            if(root->val > key){
                if(root->left && root->left->val == key){
                    root->left = helper(root->left);
                }
                else{
                    root = root->left;
                }
            }
            else{
                if(root->right && root->right->val == key){
                    root->right = helper(root->right);
                }
                else{
                    root = root->right;
                }
            }
        }
        return temp;
    }
};