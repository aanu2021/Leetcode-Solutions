class Solution {
public:
    void flatten(TreeNode* root) {
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

// root left right

// right left root

