class Solution {
public:
    
    TreeNode*lastNode = NULL;
    
    void flatten(TreeNode* root) {
        if(!root) return;
        flatten(root->right);
        flatten(root->left);
        if(lastNode){
            root->left = NULL;
            root->right = lastNode;
        }
        lastNode = root;
    }
};

// root left right

// right left root

