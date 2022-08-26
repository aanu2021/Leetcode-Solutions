class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        
        if(root==NULL){
            return NULL;
        }
        
        while(root && root->val!=val){
            
            root=(root->val > val ? root->left : root->right);
            
        }
        
        return root;
        
    }
};