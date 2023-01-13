class Solution {
    public:
    
    bool isLeaf(TreeNode* root){
        if(!root->left && !root->right) return true;
        else return false;
    }
    
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);
        TreeNode*curr = root;
        while(curr){
            if(curr->val > val){
                if(!curr->left){
                    curr->left = new TreeNode(val);
                    break;
                }
                else{
                    curr = curr->left;
                }
            }
            else{
                if(!curr->right){
                    curr->right = new TreeNode(val);
                    break;
                }
                else{
                    curr = curr->right;
                }
            }
        }
        return root;
    }
};