class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q) return root;
        TreeNode * leftNode = lowestCommonAncestor(root->left,p,q);
        TreeNode * rightNode = lowestCommonAncestor(root->right,p,q);
        if(leftNode == NULL) return rightNode;
        if(rightNode == NULL) return leftNode;
        return root;
    }
};

/*

Check whether we are able to find any of the p/q node in the left subtree of the current node.

And then the same for the right subtree of the current node.

*/