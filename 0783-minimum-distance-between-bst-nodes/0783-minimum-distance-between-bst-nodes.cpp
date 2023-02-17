class Solution {
public:
    
    void inorderTraversal(TreeNode*&root,int &prev,int &minDiff){
        if(!root) return;
        inorderTraversal(root->left,prev,minDiff);
        if(prev != -1){
            minDiff = min(minDiff,root->val - prev);
        }
        prev = root->val;
        inorderTraversal(root->right,prev,minDiff);
    }
    
    int minDiffInBST(TreeNode* root) {
        if(!root) return 0;
        int minDiff = INT_MAX;
        int prev = -1;
        inorderTraversal(root,prev,minDiff);
        return minDiff;
    }
};