class Solution {
public:
    
    int func(TreeNode*& root,int &maxDiff){
        if(!root) return 0;
        int leftHeight = func(root->left, maxDiff);
        int rightHeight = func(root->right, maxDiff);
        int maxDepth = 1 + max(leftHeight, rightHeight);
        maxDiff = max(maxDiff, abs(leftHeight-rightHeight));
        return maxDepth;
    }
    
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        int maxDiff = 0;
        func(root,maxDiff);
        return maxDiff <= 1;
    }
};