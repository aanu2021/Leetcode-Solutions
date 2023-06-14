class Solution {
public:
    
    void inorder(TreeNode* &root,int &prevVal,int &minDiff){
        
        if(!root) return;
        
        inorder(root->left,prevVal,minDiff);
        
        if(prevVal != -1){
            minDiff = min(minDiff,root->val - prevVal);
        }
        prevVal = root->val;
        
        inorder(root->right,prevVal,minDiff);
        
    }
    
    int getMinimumDifference(TreeNode* root) {
        
        if(!root) return 0;
        
        int minDiff = INT_MAX;
        int prevVal = -1;
        
        inorder(root,prevVal,minDiff);
        
        return minDiff;
        
    }
};