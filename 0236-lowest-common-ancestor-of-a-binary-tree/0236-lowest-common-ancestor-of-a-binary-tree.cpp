class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(!root || root==p || root==q) return root;
        TreeNode * leftNode = lowestCommonAncestor(root->left,p,q);
        TreeNode * rightNode = lowestCommonAncestor(root->right,p,q);
        if(leftNode == NULL) return rightNode;
        if(rightNode == NULL) return leftNode;
        return root;
        
    }
};