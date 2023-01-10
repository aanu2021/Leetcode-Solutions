class Solution {
public:
    
    int height(TreeNode*&root,int &diameter){
        if(!root) return 0;
        int left_ht = height(root->left,diameter);
        int right_ht = height(root->right,diameter);
        diameter = max(diameter,1 + left_ht + right_ht);
        return 1 + max(left_ht,right_ht);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int diameter = 0;
        height(root,diameter);
        return diameter-1;
    }
};