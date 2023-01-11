class Solution {
public:
    
    int leftMost,rightMost;
    int maxLevel;
    
    int findDeepestLevel(TreeNode*&root){
        if(!root) return 0;
        int left_depth = findDeepestLevel(root->left);
        int right_depth = findDeepestLevel(root->right);
        return 1 + max(left_depth,right_depth);
    }
    
    void getDeepestLeaves(TreeNode*&root,int lvl){
        if(!root) return;
        if(lvl == maxLevel){
            if(leftMost == -1){
                leftMost = root->val;
            }
            rightMost = root->val;
        }
        getDeepestLeaves(root->left,lvl+1);
        getDeepestLeaves(root->right,lvl+1);
    }
    
    TreeNode*findLCA(TreeNode*&root,int p,int q){
        if(root == NULL || root->val == p || root->val == q) return root;
        TreeNode * left = findLCA(root->left,p,q);
        TreeNode * right = findLCA(root->right,p,q);
        if(left == NULL) return right;
        if(right == NULL) return left;
        return root;
    }
    
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(!root) return NULL;
        maxLevel = findDeepestLevel(root);
        leftMost = -1;
        rightMost = -1;
        getDeepestLeaves(root,1);
        return findLCA(root,leftMost,rightMost);
    }
};