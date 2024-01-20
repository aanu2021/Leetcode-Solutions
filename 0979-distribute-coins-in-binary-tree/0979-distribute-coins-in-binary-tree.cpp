class Solution {
public:
    
    int func(TreeNode* root, int &numOps){
        if(!root) return 0;
        int left  = func(root->left, numOps);
        int right = func(root->right, numOps);
        numOps += abs(left) + abs(right);
        return root->val + left + right - 1;
    }
    
    int distributeCoins(TreeNode* root) {
        if(!root) return 0;
        int numOps = 0;
        func(root, numOps);
        return numOps;
    }
};